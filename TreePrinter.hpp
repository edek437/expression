#pragma once

struct ValueNode;
struct OperationNode;

class TreePrinter
{
public:
    void printValueNode(ValueNode* vNode);
    void printOperationNode(OperationNode* oNode);
};
