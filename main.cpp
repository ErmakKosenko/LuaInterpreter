#include <iostream>
#include <fstream>
#include "binary.tab.hh" 
#include "Node.h"
#include <vector>

extern Node root;
extern FILE* yyin;
std::ofstream outFile;
std::ofstream ass;
vector<string> variables;
int printNumber = 0;

void yy::parser::error(std::string const &err) {
  std::cout << "Error: " << err << std::endl;
}

int main(int argc, char **argv) {

    FILE *inFile = fopen(argv[1], "r");
    if(!inFile) {
        std::cout << "Error opening infile in function main()";
        return -1;
    }

    yyin = inFile;

    yy::parser parser;
    outFile.open("tree.dot", std::ofstream::out);
    ass.open("target.cc", std::ofstream::out);
    if (!parser.parse()) {
        root.threeAddress();
	root.assembly();
        outFile.close();
    }
    return 0;
}
