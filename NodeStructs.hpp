#pragma once
#include <string>
#include <vector>
#include "TreePrinter.hpp"
#include "EPrecendense.hpp"

struct Node
{
    Node(std::string name, EPrecendence precendence): name(name), precendence(precendence), indent(0) {}
    virtual void visit(TreePrinter* tp) = 0;
    virtual bool isValue() = 0;
    virtual bool isOperation() = 0;
    virtual void increaseIndent() = 0;
    std::string name;
    EPrecendence precendence;
    int indent;
    virtual ~Node() {}
};

struct ValueNode: public Node
{
    ValueNode(std::string name, EPrecendence precendence): Node(name, precendence) {}
    bool isValue() {return true; }
    bool isOperation() {return false; }
    void increaseIndent() { indent++;}
    void visit(TreePrinter *tp)
    {
        tp->printValueNode(this);
    }
};

struct OperationNode: public Node
{
    OperationNode(std::string name, EPrecendence precendence): Node(name, precendence) {}
    bool isValue() {return false; }
    bool isOperation() {return true; }
    void increaseIndent()
    {
        indent++;
        for (auto& node: childNodes)
          node->increaseIndent();
    }

    void visit(TreePrinter *tp)
    {
        tp->printOperationNode(this);
    }

    virtual ~OperationNode()
    {
        for (auto& node: childNodes)
            delete node;
    }
    std::vector<Node*> childNodes;
};
