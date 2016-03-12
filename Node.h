
#include <list>
#include <vector>
#include <stack>
#include <map>
#include "symboltable.h"

struct Container {
	std::vector<std::string> values;
};

extern SymbolTable symbols;

class Node {
	public:
		std::string test="test";
		std::string tag, value;
		std::list<Node> children;
		Node(std::string t, std::string v) : tag(t), value(v) {}
		Node() { tag="uninitialised"; value="uninitialised";	}  // Bison needs this.

		void dump(int depth=0) {
            std::cout << children.size();
			for(int i=0; i<depth; i++)
				std::cout << "  ";
			std::cout << tag << ":" << value << std::endl;
			for(auto i=children.begin(); i!=children.end(); i++)
				(*i).dump(depth+1);
		}

		void dotFormat(int depth = 0) {
			std::list<std::string> pointer;
			std::cout << "digraph { " << std::endl;
			std::cout << tag + "0"  << " [label=\""+tag+"\"];" << std::endl;
			for (Node e : children)
				//std::cout << tag + "0 -> " << e.tag +"1;" << std::endl;
			printChild(0,1);
			std::cout << std::endl <<  "}";
		}

		int printChild(int parent, int level) {
			int childLevel = level;
			for (auto i=children.begin(); i!=children.end(); i++) {
				level++;
				if (!i->children.empty()) {
					std::cout << i->tag + std::to_string(level) << " [label=\""+i->tag+"\"];" << std::endl;
					std::cout << tag + std::to_string(parent) << " -> " << i->tag + std::to_string(level) << ";" << std::endl;
				} else {
					if (i->value!="") {
					std::cout << i->tag + std::to_string(level) << " [label=\""+i->value+"\"];" << std::endl;
					std::cout << tag + std::to_string(parent) << " -> " << i->tag + std::to_string(level) << ";" << std::endl;
					}
					else {
						std::cout << i->tag + std::to_string(level) << " [label=\""+i->tag+"\"];" << std::endl;
						std::cout << tag + std::to_string(parent) << " -> " << i->tag + std::to_string(level) << ";" << std::endl;
					}
				}
				if (!i->children.empty()) {
					level = i->printChild(level, level);
				}
			}
			return level;
		}

		void interpret() {
			for (Node e : children) {
				if (e.tag == "block") {
					e.interpret();
				} else if (e.tag == "statementchunk") {
					e.interpret();
				} else if (e.tag == "statement") {
					e.evaluateStatement();
					std::cout << "x = " << symbols.getValue("x") << " y = " << symbols.getValue("y") << " z = " << symbols.getValue("z") << std::endl;
				}
			}
		}

		void evaluateStatement() {
			Container information;
			std::vector<std::string> returnVarlist;
			std::string explistReturn = "";
			if (children.front().tag == "functioncall") {
				information = children.front().evaluateFunctioncall();
				if (information.values[0] == "print" || information.values[0] == "io.write") {
					std::cout << std::endl << std::endl << "_______PROGRAM OUTPUT________" << std::endl;
					std::cout << information.values[1];
				}
				std::cout << std::endl;
			} else if (children.front().tag == "varlist") {
				returnVarlist = children.front().evaluateVarlist();
				// if binop...
				children.pop_front();
				if (children.front().tag == "binop" && children.front().value == "=") {
					children.pop_front();
					if (children.front().tag == "explist") {
						explistReturn = children.front().evaluateExplist();
						for (std::string var : returnVarlist) {
							symbols.insert(var, explistReturn);
						}
					}
				}
				//std::cout << "x = " << symbols.getValue("x") << " p = " << symbols.getValue("p") << std::endl;
			}
		}

		std::vector<std::string> evaluateVarlist() {
			std::vector<std::string> variableList;
			for (Node e : children) {
				if (e.tag == "var") {
					variableList.push_back(e.evaluateVar());
				}
			}
			return variableList;
		}

		std::string evaluateVar() {
			std::string variable = "";
			for (Node e : children) {
				if (e.tag == "identifier") {
					variable += e.value;
				} else if (e.tag == "prefixexp") {
					variable += e.evaluatePrefixexp();
				} else if (e.tag == "leftbracket") {

				} else if (e.tag == "exp") {

				} else if (e.tag == "rightbracket") {

				} else if (e.tag == "dot") {
					variable += ".";
				}
			}
			return variable;
		}

		Container evaluateFunctioncall() {
			std::string prefixexp, args, identifier;
			prefixexp = args = identifier = "";
			Container information;
			for(Node e : children) {
				if (e.tag == "prefixexp") {
					prefixexp += e.evaluatePrefixexp();
				} else if (e.tag == "args") {
					args += e.evaluateArg();
				} else if (e.tag == "colon") {
					args += e.value;
				} else if (e.tag == "identifier") {
					identifier += e.value;
				}
			}
			information.values.push_back(prefixexp);
			information.values.push_back(args);
			information.values.push_back(identifier);


			return information;
		}

		std::string evaluatePrefixexp() {
			Container functionInformation;
			std::string prefixexp = "";
			for (Node e : children) {
				if (e.tag == "var") {		// Retrieves the value of the idenfier if its a symbol otherwise it assumes its a functionname 
					if (e.children.front().tag == "identifier") {
						prefixexp = symbols.getValue(e.children.front().value);
						if (prefixexp == "not a symbol") {
							prefixexp = e.children.front().value;
						}
					}
				} else if (e.tag == "functioncall") {
					functionInformation = e.evaluateFunctioncall();
					//prefixexp += functionInformation.values[1];
				} else if (e.tag == "leftparentheses") {
					//prefixexp += e.value;
				} else if (e.tag == "exp") {
					prefixexp += e.evaluateExp();
				} else if (e.tag == "rightparentheses") {
					//prefixexp += e.value;
				} else if (e.tag == "term") {
					prefixexp += e.evaluateTerm();
				}
			}
			return prefixexp;
		}


		std::string evaluateArg() {
			std::string args = "";
			for (Node e : children) {
				if (e.tag == "string") {
					args += e.value;
				} else if (e.tag == "tableconstructor") {

				} else if (e.tag == "leftparentheses") {

				} else if (e.tag == "rightparentheses") {

				} else if (e.tag == "explist") {
					args += e.evaluateExplist();
				}
			}
			return args;
		}

		std::string evaluateExplist(){
			std::string explist = "";
			std::string newToken = "";
			int val1, val2;
			for (Node e : children) {
				if (e.tag == "exp") {
					newToken = e.evaluateExp();
					val1 = std::stoi(newToken);
					if (explist != "") {
						val2 = std::stoi(explist);
						val1 += val2;
					}
					explist = std::to_string(val1);
				} else if (e.tag == "comma") {
					explist += e.value;
				} else if (e.tag == "term") {
					newToken = e.evaluateTerm();
					val1 = std::stoi(newToken);
					if (explist != "") {
						val2 = std::stoi(explist);
						val1 += val2;
					}
					explist = std::to_string(val1);
				}
			}
			return explist;
		}

		std::string evaluateExp() {
			std::list<std::string> operatorList;
			std::string retvalue = "", currentToken = "", lastOp = "";
			int currentValue, retrivedValue, tokenOperation;

			for (Node e : children) {
				if (e.tag == "term") {
					retvalue = e.evaluateTerm();
					operatorList.push_back(retvalue);
				} else if (e.tag == "exp") {
					retvalue = e.evaluateExp();
					operatorList.push_front(retvalue);
				} else if (e.tag == "binop" && e.value == "+") {
					operatorList.push_back("plus");
				} else if ((e.tag == "binop" || e.tag == "unop") && e.value == "-") {
					operatorList.push_back("minus");
				} else if (e.tag == "unop" && e.value == "not") {
					operatorList.push_back("not");
				} else if (e.tag == "unop" && e.value == "hashtag") {
					operatorList.push_back("hashtag");
				}
			}
			currentToken = operatorList.front();
			operatorList.pop_front();

			if (currentToken == "-") {
				int oldValue = std::stoi(currentToken);
				oldValue = oldValue - 2*oldValue;
				operatorList.pop_front();
				operatorList.push_front(std::to_string(oldValue));
			} else if (currentToken == "not") {
				std::cout << "NOT IMPLEMENTED!";
			} else if (currentToken == "hashtag") {
				std::cout << "NOT IMPLEMENTED!";
			} else {
				operatorList.push_front(currentToken);
			}
			currentValue = 0;

			while (!operatorList.empty()) {
				currentToken = operatorList.front();
				operatorList.pop_front();
				if (currentToken == "minus") {
					lastOp = "minus";
					currentToken = operatorList.front();
					operatorList.pop_front();
					currentValue = retrivedValue - std::stoi(currentToken);
				} else if (currentToken == "plus") {
					currentToken = operatorList.front();
					operatorList.pop_front();
					currentValue = retrivedValue + std::stoi(currentToken);
				} else {
					if (currentToken != "")
						retrivedValue = std::stoi(currentToken);
				}
			}
			return std::to_string(currentValue);
		}

		std::string evaluateTerm() {
			std::list<std::string> operatorList;
			std::string retvalue = "", currentToken = "", lastOp = "";
			int currentValue, retrivedValue, tokenOperation;

			// Here the support for NIL,FALSE,TRUE and so on should be.
			if (children.size() == 1 && children.front().tag == "integer") {
				return children.front().value;
			} else {
				for (Node e : children) {
					if (e.tag == "term") {
						retvalue = e.evaluateTerm();
						operatorList.push_back(retvalue);
					} else if (e.tag == "prefixexp"){
						retvalue = e.evaluatePrefixexp();
						operatorList.push_back(retvalue);
					} else if (e.tag == "integer") {
						operatorList.push_back(e.value);
					} else if (e.tag == "binop" && e.value == "*") {
						operatorList.push_back("multiply");
					} else if (e.tag == "binop" && e.value == "/") {
						operatorList.push_back("devide");
					} else if (e.tag == "binop" && e.value == "%") {
						operatorList.push_back("percent");
					} else if (e.tag == "binop" && e.value == "^") {
						operatorList.push_back("caret");
					} else if (e.tag == "binop" && e.value == "..") {
						operatorList.push_back("dotdot");
					} else if (e.tag == "binop" && e.value == "<") {
						operatorList.push_back("lessthan");
					} else if (e.tag == "binop" && e.value == "<=") {
						operatorList.push_back("lessorequal");
					} else if (e.tag == "binop" && e.value == ">") {
						operatorList.push_back("greaterthan");
					} else if (e.tag == "binop" && e.value == ">=") {
						operatorList.push_back("greaterorequal");
					} else if (e.tag == "binop" && e.value == "==") {
						operatorList.push_back("tildeequal");
					} else if (e.tag == "binop" && e.value == "and") {
						operatorList.push_back("and");
					} else if (e.tag == "binop" && e.value == "or") {
						operatorList.push_back("or");
					}
				}

			}

			currentToken = operatorList.front();
			operatorList.pop_front();

			if (currentToken == "-") {
				int oldValue = std::stoi(currentToken);
				oldValue = oldValue - 2*oldValue;
				operatorList.pop_front();
				operatorList.push_front(std::to_string(oldValue));
			} else if (currentToken == "not") {
				std::cout << "NOT IMPLEMENTED!";
			} else if (currentToken == "hashtag") {
				std::cout << "NOT IMPLEMENTED!";
			} else {
				operatorList.push_front(currentToken);
			}
			currentValue = 0;
			if (operatorList.size() == 1) {
				return operatorList.front();
			}
			while (!operatorList.empty()) {
				currentToken = operatorList.front();
				operatorList.pop_front();
				if (currentToken == "multiply") {
					currentToken = operatorList.front();
					operatorList.pop_front();
					currentValue = retrivedValue * std::stoi(currentToken);
				} else if (currentToken == "devide") {
					currentToken = operatorList.front();
					operatorList.pop_front();
					currentValue = retrivedValue / std::stoi(currentToken);
				} else if (currentToken == "percent") {
					currentToken = operatorList.front();
					operatorList.pop_front();
					currentValue = retrivedValue % std::stoi(currentToken);
				} else if (currentToken == "caret") {
					std::cout << "IN CARET";
					int oldValue = retrivedValue;
					currentValue = oldValue;
					currentToken = operatorList.front();
					operatorList.pop_front();
					for (int i = 0; i < std::stoi(currentToken)-1; i++) {
						currentValue = currentValue * oldValue;
					}
				} else if (currentToken == "dotdot") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "lessthan") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "lessorequal") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "greaterthan") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "greaterorequal") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "equalto") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "and") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "or") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else {
					if (currentToken != "")
						retrivedValue = std::stoi(currentToken);
				}
			}
			return std::to_string(currentValue);
		}

};
