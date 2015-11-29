#include "ExpressionParser.hpp"
#include "NodeStructs.hpp"
#include <stack>
#include <iostream>
#include <cstring>
#include <algorithm>

Node *ExpressionParser::parseExpression(std::string const& exp)
{
    std::vector<Node*> nodeVect;
    nodeVect.push_back(new OperationNode("dummyNode", -2000));
    int expIndex = 0;
    std::string result;
    while (expIndex < exp.size())
    {
        std::cout<<exp.substr(expIndex)<<std::endl;
        if(isOneOf(exp, expIndex, std::vector<std::string> {" ", "\t"}, result))
        {
            expIndex++;
        }
        else if(isOneOf(exp, expIndex, openBarackets, result))
        {
            for(auto& b: bracketPairs)
            {
                if(result[0]==b[0])
                {
                    int bracketCounter = 1;
                    std::string::size_type pos = expIndex;
                    while(bracketCounter && std::string::npos!=pos)
                    {
                        pos = exp.find_first_of(b, pos+1);
                        bracketCounter += (exp[pos] == b[1] ? -1 : 1);
                    }

                    if(std::string::npos==pos)
                        throw ") is missing";
                    else
                    {
                        nodeVect.push_back(parseExpression(exp.substr(expIndex+1, pos-expIndex-1)));
                        expIndex=pos+1;
                    }
                }
            }
        }
        else if(isOneOf(exp, expIndex, compOperators, result))
        {
            if(0 == expIndex || nodeVect.back()->isOperation())
                throw "Error two operations next to each other or expression starting with operation";
            nodeVect.push_back(new OperationNode(result, 10));
            expIndex += result.size();
        }
        else if(isOneOf(exp, expIndex, logicalOperators, result))
        {
            if(result=="or")
                nodeVect.push_back(new OperationNode(result, 5));
            if(result=="and")
                nodeVect.push_back(new OperationNode(result, 6));
            expIndex += result.size();
        }
        else
        {
            if(0!=expIndex && nodeVect.back()->isValue())
                throw "Error two values next to each other";
            int valLength = 0;
            while(!(expIndex+valLength == exp.size()
                    || isOneOf(exp, expIndex+valLength, logicalOperators, result)
                    || isOneOf(exp, expIndex+valLength, compOperators, result)))
            {
                valLength++;
            }
            nodeVect.push_back(new ValueNode(exp.substr(expIndex,valLength), 100));
            expIndex += valLength;
        }
    }

    nodeVect.push_back(new ValueNode("dummyNode", -2000));
    while(nodeVect.size()!=3)
    {
        for(auto it = nodeVect.begin(); it != nodeVect.end(); ++it)
        {
            if(std::distance(it, nodeVect.end())>=3)
            {
                auto prevNode = *it;
                auto currNode = *std::next(it, 1);
                auto nextNode = *std::next(it, 2);
                if(currNode->precendence >= prevNode->precendence
                        && currNode->precendence >= nextNode->precendence)
                {
                    if(nextNode->precendence > prevNode->precendence)
                        dynamic_cast<OperationNode*>(nextNode)->childNodes.push_back(currNode);
                    else
                        dynamic_cast<OperationNode*>(prevNode)->childNodes.push_back(currNode);
                    currNode->increaseIndent();
                    currNode->precendence = 1000;
                }
            }
        }
        auto newEnd = std::remove_if(nodeVect.begin(),nodeVect.end(),[](Node* node){return node->precendence==1000;});
        nodeVect.resize(std::distance(nodeVect.begin(), newEnd));
    }
    delete nodeVect[0];
    delete nodeVect[2];
    nodeVect[1]->precendence=10;
    return nodeVect[1];
}

bool ExpressionParser::isOneOf(const std::string &str, int index, const std::vector<std::string> &vals, std::string &result)
{
     for (auto& v: vals)
     {
         if(strcmp(str.substr(index, v.size()).c_str(), v.c_str()) == 0)
         {
             result = v;
             return true;
         }
     }
     result = "";
     return false;
 }
