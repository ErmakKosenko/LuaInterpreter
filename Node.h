#ifndef NODE_H
#define NODE_H

class Node {

  std::string info, value;
public:
  Node(std::string info, std::string value) {
    this->info = info;
    this->value = value;
  }
  Node() {
    this->info = "uninitialised";
    this->value = "uninitialised";
  }
};


#endif
