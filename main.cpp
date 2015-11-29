#include "ExpressionParser.hpp"
#include "NodeStructs.hpp"
#include "TreePrinter.hpp"
#include <vector>
#include <iostream>

void runTestCase(std::string const& expression)
{
    std::cout<<"##########Run tescase for expresion########" <<std::endl;
    std::cout<<expression<<std::endl;
    ExpressionParser parser;
    TreePrinter tp;
    try
    {
        Node* mainNode = parser.parseExpression(expression);
        mainNode->visit(&tp);
        delete mainNode;
    }
    catch(const char* ex)
    {
        std::cout<<"##########Catching error#######################" <<std::endl;
        std::cout << ex << std::endl;
        std::cout<<"##########Testcase fialed for expresion########" <<std::endl;
    }
    std::cout<<"##########Testcase end for expresion########" <<std::endl;
    std::cout<<expression<<std::endl;
}

int main()
{
    runTestCase("b==4 or e==7 and f>7");
    runTestCase("a==0 and (b==4 or e==7) and f>7");
    runTestCase("(a==0 or a==9) and (b==4 or e==7) and f>7");
    runTestCase("(h>7 or (a==0 and (b==4 or e==7))) and f>7");
    return 0;
}
