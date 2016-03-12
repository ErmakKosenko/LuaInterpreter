#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>

class SymbolTable {
 public:
    std::vector<std::string> values;
    std::map<std::string, int> table;

    SymbolTable() {
        values.reserve(50);
    }

    ~SymbolTable() {

    }

    void insert(std::string name, std::string value) {
        std::string copy(value);
        int offset = table[name];
        if (offset != 0) {
            values[offset-1] = value;
        } else {
            offset = values.size();
            table[name] = offset+1;
            values.push_back(copy);
        }
    }

    std::string getValue(std::string variableName) {
        int offset = table[variableName];
        std::string temp = values[offset-1];

        if (temp != "") {
            return temp;
        } else {
            return "not a symbol";
        }
    }

    std::string updateValue(std::string name, std::string newValue) {
        values.at(table[name]-1) = newValue;
    }

};


#endif
