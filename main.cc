#include <iostream>
#include "binary.tab.hh"   //  Not really sure what this does

extern Node root;

void yy::parser::error(std::string const &err) {
  std::cout << "Syntaxerror: " << err << std::endl;
}

int main(int argc, char **argv) {
  yy::parser parser;
  if (!parser.parse()) {
    //  DO SHIT
  }
  return 0;
}
