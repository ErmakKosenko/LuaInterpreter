
#include <list>
#include <vector>
#include <stack>
#include <map>
#include "symboltable.h"
#include <fstream>
#include <iostream>
#include <sstream>

struct Container {
	std::vector<std::string> values;
};

extern SymbolTable symbols;
extern std::ofstream outFile;

class Node {
	public:
		std::string test="test";
		std::string tag, value;
		std::list<Node> children;
		Node(std::string t, std::string v) : tag(t), value(v) {}
		Node() { tag="uninitialised"; value="uninitialised";	}  // Bison needs this.


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
					outFile << i->tag + std::to_string(level) << " [label=\""+i->tag+"\"];" << std::endl;
					outFile << tag + std::to_string(parent) << " -> " << i->tag + std::to_string(level) << ";" << std::endl;
				} else {
					if (i->value!="") {
					outFile << i->tag + std::to_string(level) << " [label=\""+i->value+"\"];" << std::endl;
					outFile << tag + std::to_string(parent) << " -> " << i->tag + std::to_string(level) << ";" << std::endl;
					}
					else {
						outFile << i->tag + std::to_string(level) << " [label=\""+i->tag+"\"];" << std::endl;
						outFile << tag + std::to_string(parent) << " -> " << i->tag + std::to_string(level) << ";" << std::endl;
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
				}
			}
		}

		void evaluateStatement() {
			Container information;
			std::list<std::string> returnVarlist;
			std::string explistReturn = "", var = "", offset = "";
			if (children.front().tag == "functioncall") {
				information = children.front().evaluateFunctioncall();
			} else if (children.front().tag == "varlist") {
				// IF L.H.S CONTAINTS [] then place that var in returnVarlist not the value
				for (Node e : children.front().children) {
					if (e.children.size() == 1 && e.tag == "var") {
						returnVarlist.push_back(e.children.front().value);
					} else if (e.tag == "var") {
						for (Node g : e.children) {
							if (g.tag == "prefixexp") {
								std::string test = g.evaluatePrefixexp();
								returnVarlist.push_back(test);
							} else if (g.tag == "leftbracket") {
								returnVarlist.push_back("leftbracket");
							} else if (g.tag == "term") {
								returnVarlist.push_back(g.evaluateTerm());
							} else if (g.tag == "exp") {
								returnVarlist.push_back(g.evaluateExp());
							}
							else if (g.tag == "rightbracket") {
								returnVarlist.push_back("rightbracket");
							}
						}
					}
				}
				//returnVarlist = children.front().evaluateVarlist();
				// if binop...
				children.pop_front();
				if (children.front().tag == "binop" && children.front().value == "=") {
					children.pop_front();
					if (children.front().tag == "explist") {
						std::string insertValue;
						std::string oldInsert;
						explistReturn = children.front().evaluateExplist();
						if (explistReturn != "tables") {
							std::istringstream explistStream(explistReturn);
							while (!returnVarlist.empty()) {
								var = returnVarlist.front();
								returnVarlist.pop_front();

								if (!returnVarlist.empty() && returnVarlist.front() == "leftbracket") {
									returnVarlist.pop_front();
									offset = returnVarlist.front();
									returnVarlist.pop_front();
									returnVarlist.pop_front();

									if(!std::getline(explistStream, insertValue, ',')) {
										insertValue = oldInsert;
									}
									symbols.insertInList(var, offset, insertValue);
									oldInsert = insertValue;

								} else {
									if(!std::getline(explistStream, insertValue, ',')) {
										insertValue = oldInsert;
									}
									symbols.insert(var, insertValue);
									oldInsert = insertValue;
								}
							}

							/*
							for (std::string var : returnVarlist) {
								if(!std::getline(explistStream, insertValue, ',')) {
									insertValue = oldInsert;
								}
								symbols.insert(var, insertValue);
								oldInsert = insertValue;
							}
							*/
						} else if (explistReturn == "tables") {
							for (std::string var : returnVarlist) {
								symbols.assignList(var);
							}
						}
					}
				}
			} else if (children.front().tag == "for") {
				children.pop_front();
				if (children.front().tag == "identifier") {
					std::string firstIdentifier = children.front().value;
					children.pop_front();
					if (children.front().tag == "equal") {
						children.pop_front();
						if (children.front().tag == "term") {
							std::string returnValue = children.front().evaluateTerm();
							symbols.insert(firstIdentifier, returnValue);
							children.pop_front();
							if (children.front().tag == "comma") {
								children.pop_front();
								if (children.front().tag == "term") {
									std::string loopValue = children.front().evaluateTerm();
									int lessThan = std::stoi(loopValue);
									children.pop_front();
									if (children.front().tag == "do") {
										children.pop_front();
										for (int ident = std::stoi(symbols.getValue(firstIdentifier)) ; ident <= lessThan; symbols.updateValue(firstIdentifier, std::to_string(++ident))) {
											children.front().interpret();
										}
									} else if (children.front().tag == "comma") {
										children.pop_front();
										if (children.front().tag == "term") {
											std::string inc = children.front().evaluateTerm();
											int increment = std::stoi(inc);
											children.pop_front();
											if(children.front().tag == "do") {
												children.pop_front();
												for (int ident = std::stoi(symbols.getValue(firstIdentifier)) ; ident <= lessThan; symbols.updateValue(firstIdentifier, std::to_string(ident))) {
													children.front().interpret();
													ident += increment;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			} else if (children.front().tag == "if") {
				std::string boolean;
				children.pop_front();
				if (children.front().tag == "term") {
					boolean = children.front().evaluateTerm();
					children.pop_front();
					children.pop_front();
					if (boolean == "false") {
						children.pop_front();
						while (children.front().tag == "elseif") {
							children.pop_front();
							if (children.front().tag == "term") {
								boolean = children.front().evaluateTerm();
								children.pop_front();
								children.pop_front();
								if (boolean == "false") {
									children.pop_front();
								} else if (boolean == "true") {
									if (children.front().tag == "block") {
										children.front().interpret();
									}
									while (children.front().tag != "end") {
										children.pop_front();
									}
								}
							}
						}
						if (children.front().tag == "else") {
								children.pop_front();
								children.front().interpret();
						}
					} else if (boolean == "true") {
						if (children.front().tag == "block") {
							children.front().interpret();
						}
						while (children.front().tag != "end") {
							children.pop_front();
						}
					} else {
						std::cout << "ERROR IN RETURN VALUE IF-STATEMENT; NEITHER TRUE OR FALSE";
					}
				}
			} else if (children.front().tag == "do") {
				children.pop_front();
				if (children.front().tag == "block") {
					children.front().interpret();
				}

			} else if (children.front().tag == "while") {
				std::string boolean;
				children.pop_front();
				children.pop_back();
				if (children.front().tag == "term") {
					while (children.front().evaluateTerm() == "true") {
						children.back().interpret();
					}
				}
			} else if (children.front().tag == "repeat") {
				children.pop_front();
				do {
					children.front().interpret();
				} while (children.back().evaluateTerm() == "false");
			} else if (children.front().tag == "function") {
				std::cout << "\nLacks support for function defenitions! \nExiting...\n";
				exit(0);
			}
		}

		std::vector<std::string> evaluateVarlist() {
			std::vector<std::string> variableList;
			for (Node e : children) {
				if (e.tag == "var") {
					variableList.push_back(e.evaluateVar());
				} else if (e.tag == "comma") {
					//variableList.push_back("comma");
				}
			}
			return variableList;
		}

		std::string evaluateVar() {
			std::string variable = "";
			std::string offset = "";
			std::string listValue = "";
			for (Node e : children) {
				if (e.tag == "identifier") {
					variable += e.value;
				} else if (e.tag == "prefixexp") {
					variable += e.evaluatePrefixexp();
				} else if (e.tag == "leftbracket") {

				} else if (e.tag == "term") {
					offset = e.evaluateTerm();
					listValue = symbols.getListOffsetValue(variable, offset);
					variable = listValue;
				} else if (e.tag == "dot") {
					variable += ".";
				} else if (e.tag == "exp") {
					offset = e.evaluateExp();
					listValue = symbols.getListOffsetValue(variable, offset);
					variable = listValue;
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

			if (prefixexp == "io.read") {
				std::string indata = "";
				std::cin >> indata;
				information.values.push_back(indata);
			}

			if (prefixexp == "print" || prefixexp == "io.write") {
				std::cout << args;
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
					if (e.children.size() == 1) {
						if (e.children.front().tag == "identifier") {
							prefixexp = symbols.getValue(e.children.front().value);
							if (prefixexp == "not a symbol") {
								prefixexp = e.children.front().value;
							}
						}
					} else {
						prefixexp += e.evaluateVar();
					}
				} else if (e.tag == "functioncall") {
					prefixexp = "10";
					functionInformation = e.evaluateFunctioncall();
					prefixexp = functionInformation.values[0];
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
					std::string substring = newToken.substr(0,6);
					if (substring != "string" && substring != "booles" && substring != "false" && substring != "true" && substring != "tables") {
						val1 = std::stoi(newToken);
						explist += std::to_string(val1);
					} else if (substring == "string"){
						size_t newTokenSize = newToken.size();
						explist = newToken.substr(6,newTokenSize-5);
					} else if (substring == "booles") {
						size_t newTokenSize = newToken.size();
						explist = newToken.substr(6,newTokenSize-5);
					} else if (substring == "false" || substring == "true") {
						explist = substring;
					} else if (substring == "tables") {
						explist = substring;
					}
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
			std::string retvalue = "", currentToken = "", lastOp = "", boolean = "";
			int currentValue, retrivedValue, tokenOperation;

			// Here the support for NIL,FALSE,TRUE and so on should be.
			if (children.size() == 1 && (children.front().tag == "integer")){
				return children.front().value;
			} else if (children.size() == 1 && (children.front().tag == "string")) {
				return "string" + children.front().value;
			} else if (children.size() == 1 && (children.front().tag == "true" || children.front().tag == "false")) {
				return "booles" + children.front().value;
			} else if (children.front().tag == "tableconstructor") {
				children.front().evaluateTableconstructor();
				return "tables";
			}
			else {
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
						operatorList.push_back("equalto");
					} else if (e.tag == "binop" && e.value == "~=") {
						operatorList.push_back("tildeequal");
					} else if (e.tag == "binop" && e.value == "and") {
						operatorList.push_back("and");
					} else if (e.tag == "binop" && e.value == "or") {
						operatorList.push_back("or");
					} else if (e.tag == "unop" && e.value == "-") {
						operatorList.push_back("-");
					} else if (e.tag == "unop" && e.value == "#") {
						operatorList.push_back("#");
					} else if (e.tag == "true") {
						operatorList.push_back("true");
					} else if (e.tag == "false") {
						operatorList.push_back("false");
					}
				}

			}



			currentToken = operatorList.front();
			operatorList.pop_front();

			if (currentToken == "-") {
				currentToken = operatorList.front();
				operatorList.pop_front();
				int oldValue = std::stoi(currentToken);
				oldValue = oldValue - 2*oldValue;
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
					currentToken = operatorList.front();
					operatorList.pop_front();
					if (retrivedValue < std::stoi(currentToken)) {
						return "true";
					} else {
						return "false";
					}
				} else if (currentToken == "lessorequal") {
					currentToken = operatorList.front();
					operatorList.pop_front();
					if (retrivedValue <= std::stoi(currentToken)) {
						return "true";
					} else {
						return "false";
					}
				} else if (currentToken == "greaterthan") {
					currentToken = operatorList.front();
					operatorList.pop_front();
					if (retrivedValue > std::stoi(currentToken)) {
						return "true";
					} else {
						return "false";
					}
				} else if (currentToken == "greaterorequal") {
					currentToken = operatorList.front();
					operatorList.pop_front();
					if (retrivedValue >= std::stoi(currentToken)) {
						return "true";
					} else {
						return "false";
					}
				} else if (currentToken == "equalto") {
					currentToken = operatorList.front();
					//operatorList.pop_front();
					if (boolean == "true" || boolean == "false" || currentToken == "true" || currentToken == "false") {
						if (boolean == currentToken) {
							return "true";
						} else {
							return "false";
						}
					} else if (retrivedValue == std::stoi(currentToken)) {
						return "true";
					} else {
						return "false";
					}
				} else if (currentToken == "and") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "or") {
					std::cout << currentToken << " NOT IMPLEMENTED IN evaluateTerm()";
				} else if (currentToken == "#") {
					std::string sizeOfList = "";
					currentToken = operatorList.front();
					operatorList.pop_front();
					sizeOfList = symbols.getListSize(currentToken);
					return sizeOfList;
				} else {
					if (currentToken != "false" && currentToken != "true") {
						retrivedValue = std::stoi(currentToken);
					} else {
						boolean = currentToken;
					}
				}
			}
			return std::to_string(currentValue);
		}

		std::string evaluateTableconstructor() {
			std::string temp;
			for(Node e : children) {
				if (e.tag == "fieldlist") {
					e.evaluateFieldList();
				}
			}

			return "";

		}

		std::string evaluateFieldList() {
			std::vector<std::string> values;
			values.push_back("0");
			std::string temp;
			for(Node e : children) {
				if (e.tag == "field") {
					temp = e.evaluateField();
					values.push_back(temp);
				} else if (e.tag == "comma") {
					// DO NOTHING
				}
			}

			symbols.insertList(values);
			return "";

		}

		std::string evaluateField() {
			std::string retValue = "Error in evaluateField";
			if(children.size() == 1 && children.front().tag == "term") {
				retValue = children.front().evaluateTerm();
			}
			return retValue;
		}

};
