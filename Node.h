#pragma once

#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include "symboltable.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <climits>

extern SymbolTable symbols;
extern std::ofstream outFile;
extern int nameCounter;
extern int lableCounter;

using namespace std;

class ThreeAd
{
  public:
    string op;
    string result, lhs, rhs;

    ThreeAd(string out, string o, string l, string r)
      :  result(out), op(o), lhs(l), rhs(r)      {}

    void reUse(string out, string o, string l, string r) {
      result = out;
      op = o;
      lhs = l;
      rhs = r;
    }

    void dump()
    {
      cout << result << " := " << lhs << " "
	<< op << " " << rhs << endl;
    }

    string dumpInstructionDot() {
      if (op == "<" || op == ">" || op == "<=" || op == ">=") {
	op = "\\" + op;
      }
      stringstream temp;
      temp << result << " := " << lhs << " " << op << " " << rhs;
      return temp.str();
    }

};

class BBlock
{
  public:
    list<ThreeAd> instructions;
    BBlock *trueExit, *falseExit;

    BBlock()
      :  trueExit(NULL), falseExit(NULL)  {}

    void dump()
    {
      cout << "BBlock @ " << this << endl;
      for(auto &i : instructions)
	i.dump();
      //cout << "True: " << trueExit << endl;
      //cout << "False: " << falseExit << endl;
    }

    void dumpBlockDot () {
      int counter = 1;
      outFile << "BBlock" << this;
      outFile << " [label = \"{<f0> BBlock" << this;
      for (auto i : instructions) {
	outFile << "|<f" << counter++ << "> " << i.dumpInstructionDot() << "  \\n ";
      }
      outFile << "}\"];" << endl << endl;

      if (trueExit == falseExit && trueExit != NULL) {
	outFile << "BBlock" << this << " -> " << "BBlock" << trueExit << endl;
      } else if (trueExit != NULL && falseExit != NULL) {
	outFile << "BBlock" << this << " -> " << "BBlock" << trueExit << endl;
	outFile << "BBlock" << this << " -> " << "BBlock" << falseExit << endl;
      } else if (falseExit != NULL) {
	outFile << "BBlock" << this << " -> " << "BBlock" << falseExit << endl;
      } else if (trueExit != NULL) {
	outFile << "BBlock" << this << " -> " << "BBlock" << trueExit << endl;
      }

      outFile.flush();
    }

    void changeIFZMemoryAddress (string newAddress) {
      for (auto &i : instructions) {
	if(i.result == "IFZ") {
	  i.rhs = newAddress;
	  return;
	}
      }
    }

    void changeIFMemoryAddress (string newAddress) {
      for (auto &i : instructions) {
	if(i.result == "IF") {
	  i.rhs = newAddress;
	  return;
	}
      }
    }

    void changeGOTOMemoryAddress (string newAddress) {
      for (auto &i : instructions) {
	if(i.result == "GOTO") {
	  i.rhs = newAddress;
	  return;
	}
      }
    }
};


/* One style for expressing a simple parse-tree.

   There are many better ways to do this that use inheritence and encode
   node-type in a static class hierarchy. Instead I've smashed all the
   node types together into a single class: the code is shorter and I
   need everyone to read and understand it quickly for the lab.
 */

///////////////////////// Expressions /////////////////////////////////////

class Expression      // Implicit union of binary operators, constants and variables.
{
  public:
    class Expression *left, *right;
    char kind, op;
    int value;
    string name;

    Expression(char k, Expression *l, Expression *r)
      : kind(k), left(l), right(r)                {}

    void dump(int depth=0)
    {
      for(int i=0; i<depth; i++)
	cout << "  ";
      switch(kind)
      {
	case 'N':  cout << op << endl;    break;
	case 'V':  cout << name << endl;  break;
	case 'C':  cout << value << endl; break;
      }
      if(left!=NULL)
	left->dump(depth+1);
      if(right!=NULL)
	right->dump(depth+1);
    }
};

///////////////////////// Statements /////////////////////////////////////

class Statement
{
  public:
    vector<Expression*> expressions;
    vector<Statement*> children;
    char kind;
    Statement(char k)  : kind(k)  {}

    void dump(int indent=0)
    {
      for(int i=0; i<indent; i++)
	cout << "  ";
      cout << "Statement(" << kind << ")" << endl ;
      for( auto e: expressions )
	e->dump(indent+1);
      for( auto c: children )
	c->dump(indent+1);

    }
};

Expression *BinOp(char op, Expression *l, Expression *r);
Expression *Variable(string name);
Expression *Constant(int value);
Expression *Equality(Expression *l, Expression *r);
Statement *Assign(string target, Expression *val);
Statement *If(Expression *condition, Statement *trueSt, Statement *falseSt);
Statement *Seq(initializer_list<Statement*> ss);
string newName();
void namePass(Expression *tree, map<Expression*,string> &nameMap);
void emitPass(Expression *tree, map<Expression*,string> &nameMap, BBlock *out);
string convert(Expression *in, BBlock *out);
void convertAssign(Statement *in, BBlock *out);
void convertComparitor(Expression *in, BBlock *out);
void convertStatement(Statement *in, BBlock **current);
void convertIf(Statement *in, BBlock **current);
void convertSeq(Statement *in, BBlock **current);
void dumpCFG(BBlock *start);

class Node {
  public:
    std::string test="test";
    std::string tag, value;
    std::list<Node> children;

    static list<BBlock> blocks;

    Node(std::string t, std::string v) : tag(t), value(v) {}
    // Bison needs default constructor.
    Node() {
      tag="uninitialised";
      value="uninitialised";
    }

    void dotFormat (int depth = 0) {
      outFile << "digraph { " << endl;
      outFile << "node[shape=record]" << endl;
      //outFile << tag + "0" <<" [lable=\""+tag+"\"];" << endl;
      int counter = 0;
      for (auto &i : blocks) {
	i.dumpBlockDot();
      }
      outFile << std::endl <<  "}";
    }

    int printChild(int parent, int level) {
      int childLevel = level;
      for (auto i=children.begin(); i!=children.end(); i++) {
	level++;
	if (!i->children.empty()) {
	  outFile << i->tag + std::to_string(level) <<
	    " [label=\""+i->tag+"\"];" << std::endl;
	  outFile << tag + std::to_string(parent) << " -> " <<
	    i->tag + std::to_string(level) << ";" << std::endl;
	} else {
	  if (i->value!="") {
	    outFile << i->tag + std::to_string(level) <<
	      " [label=\""+i->value+"\"];" << std::endl;
	    outFile << tag + std::to_string(parent) << " -> " <<
	      i->tag + std::to_string(level) << ";" << std::endl;
	  }
	  else {
	    outFile << i->tag + std::to_string(level) <<
	      " [label=\""+i->tag+"\"];" << std::endl;
	    outFile << tag + std::to_string(parent) << " -> " <<
	      i->tag + std::to_string(level) << ";" << std::endl;
	  }
	}
	if (!i->children.empty()) {
	  level = i->printChild(level, level);
	}
      }
      return level;
    }

    void threeAddress () {
      bool firstBlock = true;
      for (auto i : children) {
	// If first block use root block
	if (i.tag == "block" && firstBlock) {
	  i.statementChunk();
	  firstBlock = false;
	} else if (i.tag == "statementchunk") {
	  i.statementChunk();
	}
      }
      this->dotFormat();
    }

    void block (Node *block = nullptr) {
      for (auto i : children) {
	if (i.tag == "statementchunk") {
	  i.statementChunk(block);
	}
      }
    }

    void statementChunk (Node *block = NULL) {
      for (auto i : children) {
	if (i.tag == "statement") {
	  i.statement(block);
	} else if (i.tag == "statementchunk") {
	  i.statementChunk(block);
	}
      }
    }

    void statement (Node *block = NULL) {
      string variableName = "", binop = "", explist = "";
      for (auto i : children) {
	if (i.tag == "functioncall") {
	  i.functioncall();
	} else if (i.tag == "varlist") {
	  variableName = i.varlist();
	} else if (i.tag == "binop") {
	  binop = i.value;
	} else if (i.tag == "explist") {
	  explist = i.explist();
	} else if (i.tag == "for") {
	  // Create new block and lable it
	  this->forLoop();
	} else if (i.tag == "if") {
	  this->ifStatement(block);
	}
      }
      if (binop == "=" && variableName != "") {
	if (explist == "ThreeAddrCreated" || explist == "read") {
	  ThreeAd temp(variableName, "", lastUsedName(), "");
	  Node::blocks.back().instructions.push_back(temp);
	} else if (explist != "") {
	  ThreeAd temp(variableName, "", explist, "");
	  Node::blocks.back().instructions.push_back(temp);
	}
      }
    }

    void ifStatement (Node *block = NULL) {
      for (auto i : children) {
	if (i.tag == "term") {
	  i.term();
	}
      }
      ThreeAd temp("IF", "GOTO", lastUsedName(), "TO BE CHANGED");
      Node::blocks.back().instructions.push_back(temp);

      temp.reUse("GOTO", "", lastUsedName(), "TO BE CHANGED");
      Node::blocks.back().instructions.push_back(temp);


      BBlock *previousBlock = &blocks.back();
      Node::blocks.push_back(BBlock());

      stringstream changeMemoryAddress;
      changeMemoryAddress << &blocks.back();
      string newAddress = changeMemoryAddress.str();
      previousBlock->changeIFMemoryAddress(newAddress);

      previousBlock->trueExit = &blocks.back();

      for(auto i : children) {
	if (i.tag == "block") {
	  i.block();
	}
      }

      temp.reUse("GOTO", "", lastUsedName(), "TO BE CHANGED");
      Node::blocks.back().instructions.push_back(temp);
      BBlock *gotoBlock = &blocks.back();

      Node::blocks.push_back(BBlock());
      previousBlock->falseExit = &blocks.back();
      gotoBlock->trueExit = &blocks.back();

      changeMemoryAddress.str("");
      changeMemoryAddress << &blocks.back();
      newAddress = changeMemoryAddress.str();
      gotoBlock->changeGOTOMemoryAddress(newAddress);

      stringstream changeGOTOAddress;
      changeGOTOAddress << &blocks.back();
      newAddress = changeGOTOAddress.str();
      previousBlock->changeGOTOMemoryAddress(newAddress);

      //DO THE INCREMENT THAT NEEDS TO BE DONE FOR FOOR LOOP


    }

    string forLoop () {
      //Initiate variables
      string identifier = "";
      string binop = "";
      list<string> termValues;
      bool hasIf = false;
      list<ThreeAd> forInstructions;
      // Get for loop conditions
      for (auto i : children) {
	if (i.tag == "identifier") {
	  identifier = i.value;
	} else if (i.tag == "binop") {
	  binop = i.value;
	} else if (i.tag == "term") {
	  termValues.push_back(i.term());
	}
      }
      // Push identifier assignment to current block
      ThreeAd temp(identifier, "", termValues.front(), "");
      Node::blocks.back().instructions.push_back(temp);
      termValues.pop_front();
      
      // Create new block
      BBlock *previousBlock = &blocks.back();
      blocks.push_back(BBlock());
      previousBlock->trueExit = &blocks.back();
      previousBlock->falseExit = &blocks.back();
     
      // Handle for loop then create new block
      temp.reUse(newName(), "<=", identifier, termValues.front());
      Node::blocks.back().instructions.push_back(temp);
      
      temp.reUse("IFZ", "GOTO", lastUsedName(), "TO BE CHANGED");
      Node::blocks.back().instructions.push_back(temp);

      BBlock *conditionalBlock = &blocks.back();

      blocks.push_back(BBlock());
      BBlock *forBlock = &blocks.back();
      conditionalBlock->trueExit = forBlock;

      previousBlock = &blocks.back();

      for (auto &i : children) {
	if (i.tag == "block") {
	  hasIf = i.blockHasIf();
          i.block();
	}
      }	
	


      if (!hasIf) {
	temp.reUse(newName(), "+", identifier, "1");
	previousBlock->instructions.push_back(temp);

	temp.reUse(identifier, "", lastUsedName(), "");
	previousBlock->instructions.push_back(temp);

	stringstream test545;
	test545 << conditionalBlock;
	string ttest2 = test545.str();
	temp.reUse("GOTO", "", "", ttest2);
	previousBlock->instructions.push_back(temp);

	// Swap blocks to correct
	Node::blocks.push_back(BBlock());
	previousBlock->trueExit = conditionalBlock;
      } else {
	temp.reUse(newName(), "+", identifier, "1");
	blocks.back().instructions.push_back(temp);

	temp.reUse(identifier, "", lastUsedName(), "");
	blocks.back().instructions.push_back(temp);

	temp.reUse("GOTO", "", "", "TO BE CHANGED");
	Node::blocks.back().instructions.push_back(temp);

	stringstream changeGOTOAddress;
	changeGOTOAddress << conditionalBlock;
	string newAddress = changeGOTOAddress.str();
	blocks.back().changeGOTOMemoryAddress(newAddress);

	blocks.back().trueExit = conditionalBlock;
	Node::blocks.push_back(BBlock());
      }

      //previousBlock->falseExit = &blocks.back();

      stringstream changeMemoryAddress;
      changeMemoryAddress << &blocks.back();
      string newAddress = changeMemoryAddress.str();
      previousBlock->changeIFZMemoryAddress(newAddress);
      
      conditionalBlock->changeIFZMemoryAddress(newAddress);
      conditionalBlock->falseExit = &blocks.back();
      
      changeMemoryAddress.str("");
      changeMemoryAddress << conditionalBlock;
      temp.reUse("GOTO", "", "", changeMemoryAddress.str());
      conditionalBlock->instructions.push_back(temp);

      return "";
    }

    bool blockHasIf () {
      bool hasIf = false;
      for (auto i : children) {
	if (i.tag != "if") {
	  hasIf = i.blockHasIf();
	}
	if (hasIf || i.tag == "if"){
	  return true;
	}
      }
      return hasIf;
    }

    string varlist () {
      string variableName = "";
      for (auto i : children) {
	if (i.tag == "var") {
	  variableName = i.var();
	}
      }
      return variableName;
    }

    string functioncall () {
      list<Node> waiting;
      string prefixexpValue = "", args = "";
      string returnValue = "";
      for (auto i : children) {
	if (i.tag == "prefixexp") {
	  prefixexpValue = i.prefixexp();
	} else if (i.tag == "args") {
	  args = i.args();
	}
      }
      // if args contain "ThreeAddrCreated" it will use the last used name
      if (prefixexpValue == "print" && (args == "" || args == "ThreeAddrCreated")) {
	ThreeAd temp(newName(), "print", "", lastUsedName());
	Node::blocks.back().instructions.push_back(temp);
      } else if (prefixexpValue == "print" && args != "") {
	ThreeAd temp(newName(), "print", "", args);
	Node::blocks.back().instructions.push_back(temp);
      } else if (prefixexpValue == "io.write" && args != "") {
	ThreeAd temp(newName(), "io.write", "", args);
	Node::blocks.back().instructions.push_back(temp);
      } else if (prefixexpValue == "io.read" && args != "") {
	ThreeAd temp(newName(), "io.read", "", args);
	Node::blocks.back().instructions.push_back(temp);
	returnValue = "read";
      }
      return returnValue;
    }

    string prefixexp () {
      string varName = "";
      string returnValue = "";
      for (auto i : children) {
	if (i.tag == "var") {
	  varName = i.var();
	  if (varName == "") {
	    cout << "\nError in prefixexp; var return string \"\"";
	  } else {
	    returnValue = varName;
	  }
	} else if (i.tag == "exp") {
	  i.exp();
	} else if (i.tag == "functioncall") {
	  returnValue = i.functioncall();
	}
      }
      return returnValue;
    }

    string var () {
      string name = "";
      for (auto i : children) {
	if(i.tag == "identifier") {
	  name += i.value;
	} else if (i.tag == "prefixexp") {
	  name += i.prefixexp();
	} else if (i.tag == "dot") {
	  name += ".";
	}
      }
      return name;
    }

    string args () {
      string returnValue = "";
      for (auto i : children) {
	if (i.tag == "explist") {
	  returnValue = i.explist();
	} else if (i.tag == "string") {
	  returnValue = i.value;
	}
      }
      return returnValue;
    }

    string explist () {
      Node firstChild;
      queue<Node> evaluateExp;
      string returnValue = "";
      for (auto i : children) {
	if (i.tag == "exp") {
	  // Bottom first
	  returnValue = i.exp();
	} else if (i.tag == "term") {
	  if (i.termHasBinop()) {
	    i.term();
	    returnValue = "ThreeAddrCreated";
	  } else {
	    returnValue = i.term();
	  }

	}
      }
      return returnValue;
    }

    string exp () {
      string termValue = "";
      bool term = true, termsHasValue = true, termHasTerm = false;
      string op = "";
      list<string> values;
      string createdThreeAdressCode = "noThreeAddr";
      for (auto i : children) {
	if (i.tag == "term") {
	  if (i.termHasTerm()) {
	    termHasTerm = true;
	  }
	  termValue = i.term();
	  if (termValue == "") {
	    termsHasValue = false;
	  } else {
	    values.push_back(termValue);
	  }
	} else if (i.tag == "binop") {
	  op = i.value;
	} else {
	  term = false;
	}
      }
      if (term && termsHasValue && !termHasTerm) {
	string temp1, temp2;
	temp1 = values.front(); values.pop_front();
	temp2 = values.front(); values.pop_front();
	ThreeAd temp(newName(), op, temp1, temp2);
	Node::blocks.back().instructions.push_back(temp);
	createdThreeAdressCode = "ThreeAddrCreated";
      } else if (term && termsHasValue && termHasTerm) {
	string temp1, temp2;
	temp1 = values.front(); values.pop_front();
	ThreeAd temp(newName(), op, temp1, lastUsedName());
	Node::blocks.back().instructions.push_back(temp);
	createdThreeAdressCode = "ThreeAddrCreated";
      }
      return createdThreeAdressCode;
    }
    //ThreeAd(string out, string o, string l, string r)
    bool termHasTerm () {
      bool hasTerm = false;
      for (auto i : children) {
	// Assume if a term has a prefixexp it only contains an expression
	if (i.tag == "term") {
	  return true;
	}
      }
      return false;
    }

    bool termHasBinop () {
      bool hasBinOp = false;
      for (auto i : children) {
	if (i.tag == "binop") {
	  hasBinOp = true;
	}
      }
      return hasBinOp;
    }

    string term () {
      string returnValue = "", op = "";
      bool hasPrefixexp = false, hasInteger = false, hasBinOp = false,
	   hasTerm = false, prefixexpFirstChild = true;
      int index = 0;
      list<string> returnValues;
      for (auto i : children) {
	if (i.tag == "integer") {
	  returnValue = i.value;
	  hasInteger = true;
	} else if (i.tag == "term"){
	  returnValue = i.term();
	  returnValues.push_back(returnValue);
	  hasTerm = true;
	} else if (i.tag ==  "prefixexp") {
	  returnValue = i.prefixexp();
	  returnValues.push_back(returnValue);
	  hasPrefixexp = true;
	  if (index > 0) {
	    prefixexpFirstChild = false;
	  }
	} else if (i.tag == "binop") {
	  op = i.value;
	  hasBinOp = true;
	} else if (i.tag == "string") {
	  returnValue = i.value;
	}
	index++;
      }
      if ((hasPrefixexp || hasTerm) && hasBinOp && hasInteger) {
	if (prefixexpFirstChild) {
	  ThreeAd temp(newName(), op, lastUsedName(), returnValue);
	  Node::blocks.back().instructions.push_back(temp);
	} else {
	  ThreeAd temp(newName(), op, returnValue, lastUsedName());
	  Node::blocks.back().instructions.push_back(temp);
	}
      } else if (returnValues.size() == 2 && hasBinOp) {
	string temp1 = returnValues.front(); returnValues.pop_front();
	string temp2 = returnValues.front(); returnValues.pop_front();
	ThreeAd temp(newName(), op, temp1, temp2);
	Node::blocks.back().instructions.push_back(temp);
      }

      return returnValue;
    }

    string newName()
    {
      stringstream result;
      result << "_t" << nameCounter++;
      return result.str();
    }

    string newLable()
    {
      stringstream result;
      result << "_L" << lableCounter++;
      return result.str();
    }

    string lastUsedName() {
      stringstream result;
      result << "_t" << (nameCounter-1);
      return result.str();
    }

    string lastUsedLable() {
      stringstream result;
      result << "_L" << (lableCounter-1);
      return result.str();
    }

    // Iterate through the BBlock nodes in the CFG and dump each one
    // exactly once. This is provided as an example of marking nodes
    // in a graph and implementing traversals.
    void dumpCFG(BBlock *start)
    {
      set<BBlock *> done, todo;
      todo.insert(start);
      while(todo.size()>0)
      {
	// Pop an arbitrary element from todo set
	auto first = todo.begin();
	BBlock *next = *first;
	todo.erase(first);

	next->dump();
	done.insert(next);
	if(next->trueExit!=NULL && done.find(next->trueExit)==done.end())
	  todo.insert(next->trueExit);
	if(next->falseExit!=NULL && done.find(next->falseExit)==done.end())
	  todo.insert(next->falseExit);
      }
    }

    list<BBlock> initBBlockList() {
      list<BBlock> tmp;
      tmp.push_back(BBlock());
      return tmp;
    }

};
