#include "TreePrinter.hpp"
#include "NodeStructs.hpp"
#include <iostream>


void TreePrinter::printOperationNode(OperationNode *oNode)
{
    std::cout<<std::string(oNode->indent,'\t')<<oNode->name<<std::endl;
    for(auto& child: oNode->childNodes)
        child->visit(this);
}

void TreePrinter::printValueNode(ValueNode *vNode)
{
    std::cout<<std::string(vNode->indent,'\t')<<vNode->name<<std::endl;
}

