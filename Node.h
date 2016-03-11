
#include <vector>
#include <stack>

struct Container {
	std::vector<std::string> values;
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

			std::cout << std::endl << "Prefix: " << information.values[0] << std::endl;
			std::cout << "Args: " << information.values[1];
			std::cout << std::endl << std::endl << "_______PROGRAM OUTPUT________" << std::endl;


			if (information.values[0] == "print" || information.values[0] == "io.write") {
				std::cout << information.values[1];
			}
			std::cout << std::endl;

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
					prefixexp += functionInformation.values[1];
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
			for (Node e : children) {
				if (e.tag == "exp") {
					explist += e.evaluateExp();
				} else if (e.tag == "comma") {
					explist += e.value;
				}
			}
			return explist;
		}

		std::string evaluateExp() {
			std::string exp = "", temp = "";
			std::list<std::string> values;
			std::list<std::string> output;
			std::stack<std::string> operatorStack;
			for (Node e : children) {
				if (e.tag == "nil") {
					exp += e.value;
				} else if (e.tag == "false") {
					exp += e.value;
				} else if (e.tag == "true") {
					exp += e.value;
				} else if (e.tag == "integer") {
					values.push_back(e.value);
					exp += e.value;
				} else if (e.tag == "decimal") {
					exp += e.value;
					values.push_back(e.value);
				} else if (e.tag == "powerof") {
					exp += e.value;
					values.push_back(e.value);
				} else if (e.tag == "hexadecimal") {
					exp += e.value;
					values.push_back(e.value);
				} else if (e.tag == "string") {
					exp += e.value;
				} else if (e.tag == "dotdotdot") {
					exp += e.value;
				} else if (e.tag == "function") {

				} else if (e.tag == "prefixexp") {
					temp = e.evaluatePrefixexp();
					exp += temp;
					values.push_back(temp);
				} else if (e.tag == "tableconstructor") {

				} else if (e.tag == "binop") {
					values.push_back(e.value);
					exp += e.value;
					/*
					int val1, val2;
					std::string sval1, sval2;
					std::string binop = e.value;
					exp += e.value;
					sval1 = values.top();
					values.pop();
					sval2 = values.top();
					values.pop();
					val1 = std::stoi(sval1);
					val2 = std::stoi(sval2);
					if (binop == "+") {
						val1 = val2 + val1;
					} else if (binop == "-") {
						val1 = val2 - val1;
					} else if (binop == "*") {
						val1 = val2 * val1;
					} else if (binop == "/") {
						std::cout << "/////" << val1 << " " << val2;
						val1 = val2 / val1;
					} else if (binop == "^") {
						int temp1 = val2;
						for(int i = 1; i < val1; i++)
							val2 = val2 * temp1;
						val1 = val2;
					} else if (binop == "%") {
						val1 = val2 % val1;
						std::cout << "VAL!%%%%" << val1;
					}
					values.push(std::to_string(val1));
					*/
				} else if (e.tag == "unop") {
					exp += e.value;
					//values.push(e.value);
				}
			}
			/*
			while (!values.empty()) {
				std::string currentToken = values.front();
				std::string operatorToken = "";
				values.pop_front();
				if (currentToken != "+" || currentToken != "-" || currentToken != "*" || currentToken != "/" || currentToken != "" || currentToken != "%+") {
					output.push_back(currentToken);
				} else if (true) {
					while (!operatorStack.empty() && currentToken ) {
						operatorToken = operatorStack.top();
					}
				}
			}
			*/


			for (std::string e : values) {
				std::cout << e << " ";
			}
			std::cout << std::endl;
			return exp;
		}

		std::string shuntingYardAlgo(std::string input) {
			std::stack<std::string> operatorStack;
			std::string output;

			return "";
		}

};
