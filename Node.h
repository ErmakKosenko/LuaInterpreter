#pragma once

#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include "symboltable.h"
#include "Tree.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <climits>

extern SymbolTable symbols;
extern std::ofstream outFile;
extern int nameCounter;

using namespace std;

class ThreeAd
{
public:
  string op;
  string result, lhs, rhs;

  ThreeAd(string out, string o, string l, string r)
    :  result(out), op(o), lhs(l), rhs(r)      {}

  void dump()
  {
    cout << result << " := " << lhs << " "
         << op << " " << rhs << endl;
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
    for(auto i : instructions)
      i.dump();
    cout << "True: " << trueExit << endl;
    cout << "False: " << falseExit << endl;
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


		void dotFormat(int depth = 0) {
			std::list<std::string> pointer;
			outFile << "digraph { " << std::endl;
			outFile << tag + "0"  << " [label=\""+tag+"\"];" << std::endl;
			for (Node e : children)
				//std::cout << tag + "0 -> " << e.tag +"1;" << std::endl;
			printChild(0,1);
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
				cout << i.tag << " " << i.value << endl;;
				// If first block use root block
				if (i.tag == "block" && firstBlock) {
					i.statementChunk();
					firstBlock = false;
				} else if (i.tag == "statementchunk") {
					i.statementChunk();
				}
			}
			cout << endl << endl;
			dumpCFG(&blocks.front());
		}

		void block () {
			for (auto i : children) {
				cout << i.tag << " " << i.value << endl;
				if (i.tag == "statementchunk") {
					i.statementChunk();
				}
			}
		}

		void statementChunk () {
			for (auto i : children) {
				cout << i.tag << " " << i.value << endl;
				if (i.tag == "statement") {
					i.statement();
				} else if (i.tag == "statementchunk") {
					i.statementChunk();
				}
			}
		}

		void statement () {
			for (auto i : children) {
				cout << i.tag << " " << i.value << endl;
				if (i.tag == "functioncall") {
					i.functioncall();
				}
			}
		}

		void functioncall () {
			list<Node> waiting;
			for (auto i : children) {
				cout << i.tag << " " << i.value << endl;
				if (i.tag == "prefixexp") {
					//i.prefixexp();
					waiting.push_back(i);
				} else if (i.tag == "args") {
					i.args();
				}
			}
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
				}
			}
			return returnValue;
		}

		string var () {
			string name = "";
			for (auto i : children) {
				if(i.tag == "print") {
					name = i.value;
				}
			}
			return name;
		}

		void args () {
			for (auto i : children) {
				if (i.tag == "explist") {
					i.explist();
				}
			}
		}

		void explist () {
			Node firstChild;
			queue<Node> evaluateExp;
			for (auto i : children) {
				if (i.tag == "exp") {
					// Bottom first
					i.exp();
				}
			}
		}

		void exp () {
			string termValue = "";
			bool term = true, termsHasValue = true, termHasTerm = false;
			string op = "";
			list<string> values;
			for (auto i : children) {
				cout << i.tag << " " << i.value << endl;
				if (i.tag == "term") {
					if (i.termHasTerm()) {
						termHasTerm = true;
					}
					termValue = i.term();
					values.push_back(termValue);
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
			cout << "Termvalue: " << term << "termsHasValue: " << termsHasValue << endl;
			if (term && termsHasValue && !termHasTerm) {
				string temp1, temp2;
				temp1 = values.front(); values.pop_front();
				temp2 = values.front(); values.pop_front();
				ThreeAd temp(newName(), op, temp1, temp2);
				Node::blocks.back().instructions.push_back(temp);
			} else if (term && termsHasValue && termHasTerm) {
				string temp1, temp2;
				temp1 = values.front(); values.pop_front();
				ThreeAd temp(newName(), op, temp1, lastUsedName());
				Node::blocks.back().instructions.push_back(temp);
			}

		}
		//ThreeAd(string out, string o, string l, string r)
		bool termHasTerm () {
			bool hasTerm = false;
			for (auto i : children) {
			// Assume if a term has a prefixexp it only contains an expression
				if (i.tag == "term" || i.tag == "prefixexp") {
					return true;
				}
			}
			return false;
		}

		string term () {
			string returnValue = "", op = "";
			bool hasPrefixexp = false, hasInteger = false, hasBinOp = false,
			hasTerm = false, prefixexpFirstChild = true;
			int index = 0;

			for (auto i : children) {
				cout << i.tag << " " << i.value << endl;
				if (i.tag == "integer") {
					returnValue = i.value;
					hasInteger = true;
				} else if (i.tag == "term"){
					returnValue = i.term();
					hasTerm = true;
				} else if (i.tag ==  "prefixexp") {
					i.prefixexp();
					returnValue = "prefix";
					hasPrefixexp = true;
					if (index > 0) {
						prefixexpFirstChild = false;
					}
				} else if (i.tag == "binop") {
					op = i.value;
					hasBinOp = true;
				}
				index++;
			}
			cout << "CHECK VALUES: " <<  hasPrefixexp <<  hasBinOp << hasInteger;
			if ((hasPrefixexp || hasTerm) && hasBinOp && hasInteger) {
				if (prefixexpFirstChild) {
					ThreeAd temp(newName(), op, lastUsedName(), returnValue);
					Node::blocks.back().instructions.push_back(temp);
				} else {
					ThreeAd temp(newName(), op, returnValue, lastUsedName());
					Node::blocks.back().instructions.push_back(temp);
				}
			}

			return returnValue;
		}

		string newName()
		{
			stringstream result;
		  	result << "_t" << nameCounter++;
		  	return result.str();
		}

		string lastUsedName() {
			stringstream result;
			result << "_t" << (nameCounter-1);
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
