#pragma once
#include <string>
#include <vector>
#include <memory>

class Node;
class SubExpression;

class ExpressionParser
{
public:
    Node* parseExpression(std::string const& exp);
private:
    bool isOneOf(std::string const& str, int index, std::vector<std::string> const& vals, std::string& result);
    std::vector<std::string> compOperators = std::vector<std::string> {"==", "<=", "<", ">=", ">", "!="};
    std::vector<std::string> logicalOperators = std::vector<std::string> {"and", "or"};
    std::vector<std::string> openBarackets = std::vector<std::string> {"(", "{"};
    std::vector<std::string> bracketPairs = std::vector<std::string> {"()", "{}"};
};
