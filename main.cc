#include <iostream>
#include "binary.tab.hh"   //  Not really sure what this does
#include "symboltable.h"

extern Node root;
SymbolTable symbols;
std::ofstream outFile;

void yy::parser::error(std::string const &err) {
  std::cout << "Error: " << err << std::endl;
}

int main(int argc, char **argv) {
  yy::parser parser;
  outFile.open("source.dot", std::ofstream::out);
  if (!parser.parse()) {
      //root.dump();
      root.dotFormat();
      outFile.close();
      root.interpret();
      system ("dot -Tpdf source.dot -otree.pdf");
    //  DO SHIT
  }
  return 0;
}
