#pragma once

#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

extern std::ofstream ass;
extern std::ofstream outFile;
extern int nameCounter;
extern int lableCounter;
extern vector<string> variables;
extern int printNumber;


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

		void dumpVariable() {
			
			if (op != "print" && op != "io.write" && op != "GOTO" && result != "GOTO") {
				if (find(variables.begin(), variables.end(), result) == variables.end()) {	
					ass << "\t\t\"" << result << ": .quad 0;\"" << endl;
					variables.push_back(result);
				}		
			}
			else if (op == "print" || op == "io.write") {
				bool variableExist = false;
				for (auto i : variables) {
					if (i == rhs)
						variableExist = true;
				}
				//Variable exist and should print number
				if (variableExist) {
					//Do nothing
				} else if (op == "print"){
					//No variable exist and rhs is a string
					ass << "\t\t\"s" << printNumber++ << ": .string \\\"" << rhs << "\\n\\\";\"" << endl;		
				} else {
					ass << "\t\t\"s" << printNumber++ << ": .string \\\"" << rhs << "\\\";\"" << endl;
				}
					
			}			
		}

		void addrAssembly() {
			//Test if lhs is a number or variable
			char *r, *l;
			long convertedLeft = strtol(lhs.c_str(), &l, 10);
			long convertedRight = strtol(rhs.c_str(), &r, 10);
			vector<string> usedRegisters;
			if (op == "-") {
				//Is variable
				if (!*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %r9;\"" << endl;
				} else if (*r && !*l) {
					ass << "\t\t\"movq  $"<< lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %r9;\"" << endl;
				} else if (*l && !*r) {
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $"<< rhs << ", %r9;\"" << endl;
				} else {
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq "<< rhs << ", %r9;\"" << endl;
				}
				ass << "\t\t\"subq " << "%r9" << ", %r8;\"" << endl;
				ass << "\t\t\"movq " << "%r8, " << result << ";\"" << endl;
			} else if (op == "+") {
				//Is variable
				if (!*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %r9;\"" << endl;
				} else if (*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %r9;\"" << endl;
				} else if (*l && !*r){
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $"<< rhs << ", %r9;\"" << endl;
				} else {
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq "<< rhs << ", %r9;\"" << endl;
				}
				ass << "\t\t\"addq " << "%r9" << ", %r8;\"" << endl;
				ass << "\t\t\"movq " << "%r8, " << result << ";\"" << endl;
			} else if (op == "/" || op == "%") {
				if (!*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %rbx;\"" << endl;
				} else if (*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %rbx;\"" << endl;
				} else if (*l && !*r){
					ass << "\t\t\"movq " << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %rbx;\"" << endl;
				} else {
					ass << "\t\t\"movq " << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %rbx;\"" << endl;
				}	
				ass << "\t\t\"xorq " << "%rdx, %rdx;\"" << endl;
				ass << "\t\t\"divq " << "%rbx ;\"" << endl;
				if (op == "/")
					ass << "\t\t\"movq " << "%rax, " << result << ";\"" << endl;
				else if (op == "%")
					ass << "\t\t\"movq " << "%rdx, " << result << ";\"" << endl;
			} else if (op == "*") {
				if (!*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %rbx;\"" << endl;

				} else if (*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %rbx;\"" << endl;
				} else if (*l && !*r){
					ass << "\t\t\"movq " << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %rbx;\"" << endl;
				} else {
					ass << "\t\t\"movq " << lhs << ", %rax;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %rbx;\"" << endl;
				}
				ass << "\t\t\"mulq " << "%rbx ;\"" << endl;
				ass << "\t\t\"movq " << "%rax, " << result << ";\"" << endl;	
			} else if (op == "<=") {
				if (!*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %r9;\"" << endl;
				} else if (*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %r9;\"" << endl;
				} else if (*l && !*r){
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %r9;\"" << endl;
				} else {
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %r9;\"" << endl;
				}
				ass << "\t\t\"cmpq %r9, %r8;\"" << endl;
				ass << "\t\t\"jg BBlock";
			} else if (op == "==") {
				if (!*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %r9;\"" << endl;
				} else if (*r && !*l) {
					ass << "\t\t\"movq $" << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %r9;\"" << endl;
				} else if (*l && !*r){
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq $" << rhs << ", %r9;\"" << endl;
				} else {
					ass << "\t\t\"movq " << lhs << ", %r8;\"" << endl;
					ass << "\t\t\"movq " << rhs << ", %r9;\"" << endl;
				}
				ass << "\t\t\"cmpq %r9, %r8;\"" << endl;
				ass << "\t\t\"je BBlock";
			} else if (op == "GOTO") { //Get adress to jump and append to jg
				ass << rhs << ";\"" << endl;
			} else if (op == "") { //operator "" is assignment only but GOTO also has same op value...
				if (!*l && result != "GOTO") {
					ass << "\t\t\"movq $" << lhs << ", " << "%r8" << ";\"" << endl;
					ass << "\t\t\"movq " << "%r8, " << result << ";\"" << endl;
				} else if (result != "GOTO") {
					ass << "\t\t\"movq " << lhs << ", " << "%r8" << ";\"" << endl;	
					ass << "\t\t\"movq " << "%r8, " << result << ";\"" << endl;
				} else if (result == "GOTO") {	
					ass << "\t\t\"jmp BBlock" << rhs << ";\"" << endl;
				}
			} else if (op == "print" || op == "io.write") {
				bool variableExist = false;	
				for (auto i : variables) {
                                        if (i == rhs)
                                                variableExist = true;
                                }
				if (variableExist) {
					ass << "\t\t\"pushq %rbx;\"" << endl;
					if (op == "print")
						ass << "\t\t\"leaq  formatNL(%rip), %rdi;\"" << endl;
					else
						ass << "\t\t\"leaq  format(%rip), %rdi;\"" << endl;
					ass << "\t\t\"mov " << rhs << ", %esi;\"" << endl;
					ass << "\t\t\"xor   %eax, %eax;\"" << endl;
					ass << "\t\t\"call  printf;\"" << endl;
					ass << "\t\t\"popq  %rbx;\"" << endl;
				} else {
					ass << "\t\t\"pushq %rbx;\"" << endl;
                                        ass << "\t\t\"leaq  s" << printNumber++ <<  "(%rip), %rdi;\"" << endl;
                                        ass << "\t\t\"xor   %eax, %eax;\"" << endl;
                                        ass << "\t\t\"call  printf;\"" << endl;
                                        ass << "\t\t\"popq  %rbx;\"" << endl;
				}
			} else if (op == "io.read") {
				ass << "\t\t\"xorq %rax, %rax;\"" << endl;
				ass << "\t\t\"subq $8, %rsp;\"" << endl;
				ass << "\t\t\"movq $0, %rax;\"" << endl;	
				ass << "\t\t\"movq $" << result << ", %rsi;\"" << endl;
				ass << "\t\t\"movq $format, %rdi;\"" << endl;
				ass << "\t\t\"call scanf;\"" << endl;
				ass << "\t\t\"addq $8, %rsp;\"" << endl;
			} 
		}
};

class BBlock
{
	public:
		list<ThreeAd> instructions;
		BBlock *trueExit, *falseExit;

		BBlock()
			:  trueExit(NULL), falseExit(NULL)  {}

		void variableDump() {
			for (auto &i : instructions) {
				i.dumpVariable();
			}
		}

		void blockAssembly() {
			ass << "\t\t\"BBlock" << this << ":" << ";\"" << endl;
			for (auto &i : instructions) {
				i.addrAssembly();
			}
		}

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

string newName();

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

		void assembly() {
			ass << "#include <stdio.h>" << endl;
			ass << "int main() {" << endl;



			ass << "\tasm volatile(" << endl;
			ass << "\t\t\".section .data;\"" << endl;	
			ass << "\t\t\"format: .string \\\"%d\\\";\"" << endl;
			ass << "\t\t\"formatNL: .string \\\"%d\\n\\\";\"" << endl;
			//Output variables
			for (auto &i : blocks) {
				i.variableDump();
			}
			//reset printnumber variable
			printNumber = 0;
			ass << "\t\t\".section .text;\"" << endl;
			for (auto &i : blocks) {
				i.blockAssembly();
			}
			ass << "\t);" << endl;
			ass << "}";			   
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
			changeMemoryAddress << previousBlock;
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
				string temp1;
				temp1 = values.front(); values.pop_front();
				ThreeAd temp(newName(), op, lastUsedName(), temp1);
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
