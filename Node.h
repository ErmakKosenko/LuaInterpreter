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
};
