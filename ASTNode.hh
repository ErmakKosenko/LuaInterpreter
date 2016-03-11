#ifndef ASTNODE_H
#define ASTNODE_H

#include <memory>


enum nodeType {
    none,
    OperatorPLUS,
    OperatorMINUS,
    OperatorMULTIPLY,
    OperatorDEVIDE,
    OperatorCARET,
    OperatorPERCENT,
    OperatorDOTDOT,
    OperatorLESSTHAN,
    OperatorLESSOREQUAL,
    OperatorGREATERTHAN,
    OperatorGREATEROREQUAL,
    OperatorEQUALTO,
    OperatorTILDEEQUAL,
    OperatorAND,
    OperatorOR,
    UnaryNOT,
    UnnaryHASHTAG
};

template <typename T>
class ASTNode {
public:
    nodeType type;
    T value;
    std::shared_ptr<ASTNode> leftChild;
    std::shared_ptr<ASTNode> rightChild;

    Node() {
        type = none;
        value = NULL;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};


#endif ASTNODE_H
