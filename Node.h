
#include <list>
#include <stack>

struct Container {
	std::list<std::string> values;
};


class Node {
	public:
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
				}
			}
		}

		void evaluateStatement() {
			Container information;
			for(Node e : children) {
				if (e.tag == "functioncall") {
					information = e.evaluateFunctioncall();
				}
			}
			/*
			std::cout << std::endl << "Prefix: " << information.values[0] << std::endl;
			std::cout << "Args: " << information.values[1];
			std::cout << std::endl << std::endl << "_______PROGRAM OUTPUT________" << std::endl;


			if (information.values[0] == "print" || information.values[0] == "io.write") {
				std::cout << information.values[1];
			}
			std::cout << std::endl;
			*/
		}

		Container evaluateFunctioncall() {
			std::string prefixexp, args, identifier;
			prefixexp = args = identifier = "";
			Container information;
			for(Node e : children) {
				if (e.tag == "prefixexp") {
					prefixexp = e.evaluatePrefixexp();
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
				if (e.tag == "var") {
					prefixexp += e.evaluateVar();
				} else if (e.tag == "functioncall") {
					functionInformation = e.evaluateFunctioncall();
					//prefixexp += functionInformation.values[1];
				} else if (e.tag == "leftparentheses") {
					//prefixexp += e.value;
				} else if (e.tag == "exp") {
					prefixexp += e.evaluateExp();
				} else if (e.tag == "rightparentheses") {
					//prefixexp += e.value;
				}
			}
			return prefixexp;
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
				}
			}
			std::cout << explist;
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

			for (std::string e : operatorList) {
				std::cout << e << " ";
			}
			std::cout << std::endl;

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

			for (std::string e : operatorList) {
				std::cout << e << " ";
			}

			while (!operatorList.empty()) {
				currentToken = operatorList.front();
				operatorList.pop_front();
				std::cout << "CurrentToken: " << currentToken;
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
					retrivedValue = std::stoi(currentToken);
				}
			}
			std::cout << currentValue << "    ";
			return std::to_string(currentValue);
		}

		std::string evaluateTerm() {

			if (children.size() == 1 && children.front().tag == "integer") {
				return children.front().value;
			}

			return "20";
		}

};
