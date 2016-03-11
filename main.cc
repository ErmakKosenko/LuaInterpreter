#include <iostream>
#include "binary.tab.hh"   //  Not really sure what this does

extern Node root;

void yy::parser::error(std::string const &err) {
  std::cout << "Error: " << err << std::endl;
}

int main(int argc, char **argv) {
  yy::parser parser;
  if (!parser.parse()) {
      //root.dump();
      root.dotFormat();
      root.interpret();
      root.shuntingYardAlgo("4+4");
    //  DO SHIT
  }
  return 0;
}
