#include <iostream>
#include <fstream>
#include "binary.tab.hh"   //  Not really sure what this does
#include "symboltable.h"

extern Node root;
extern FILE* yyin;
SymbolTable symbols;
std::ofstream outFile;

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
    outFile.open("source.dot", std::ofstream::out);
    if (!parser.parse()) {
        root.dotFormat();
        outFile.close();
        system ("dot -Tpdf source.dot -otree.pdf");
        root.interpret();
    }
    return 0;
}
