#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>

class SymbolTable {
 public:
    std::vector<std::string> values;
    std::vector<std::vector<std::string>> lists;
    std::map<std::string, int> table;
    std::map<std::string, int> listTable;

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
        int offset = 0;
        std::string temp = "";
        offset = table[variableName];
        if(offset != 0)
            temp = values[offset-1];

        if (temp != "") {
            return temp;
        } else {
            return "not a symbol";
        }
    }

    std::string updateValue(std::string name, std::string newValue) {
        int offset = table[name];
        values[offset-1] = newValue;

        return "";
    }

    void insertList(std::vector<std::string> insertList) {
        lists.push_back(insertList);
    }

    void assignList(std::string listName) {
        listTable[listName] = lists.size() - 1;
    }

    std::string getListSize(std::string listName) {
        int offset = listTable[listName], size = 0;
        std::string returnValue;
        if (offset < 0) {
            returnValue =  "Error in getListSize()";
        } else {
            size = lists[offset].size()-1;
            returnValue = std::to_string(size);
        }
        return returnValue;
    }

    std::string getListOffsetValue(std::string listName, std::string valueAt) {
        std::string returnValue = "";
        int offsetList = listTable[listName];
        if (offsetList < 0) {
            returnValue = "Error in getListOffsetValue";
        } else {
            returnValue = lists[offsetList][std::stoi(valueAt)];
        }
        return returnValue;
    }

    void insertInList(std::string listName, std::string at, std::string value) {
        int listOffset = listTable[listName];
        lists[listOffset][std::stoi(at)] = value;
    }

};


#endif
