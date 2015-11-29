//#include <ktest/ktest.hpp>
//#include "ExpressionParser.hpp"
//#include "NodeStructs.hpp"
//#include "TreePrinter.hpp"
//#include <vector>
//#include <iostream>

//struct Record
//{
//    Record(int a, int b, int c, int d, int e, int f, int g, int h)
//        : a(a)
//        , b(b)
//        , c(c)
//        , d(d)
//        , e(e)
//        , f(f)
//        , g(g)
//        , h(h)
//    {}
//    int a;
//    int b;
//    int c;
//    int d;
//    int e;
//    int f;
//    int g;
//    int h;
//    void printFormatter(std::string const& fieldName, int fieldValue)
//    {
//        std::cout<<fieldName<<"="<<fieldValue<<std::endl;
//    }

//    void print()
//    {
//        std::cout<<"Record detail:"<<std::endl;
//        printFormatter("a",a);
//        printFormatter("b",b);
//        printFormatter("c",c);
//        printFormatter("d",d);
//        printFormatter("e",e);
//        printFormatter("f",f);
//        printFormatter("g",g);
//        printFormatter("h",h);
//        std::cout<<"Record end"<<std::endl;
//    }
//};

//class DatabseTests : public ktest::Test
//{
//public:
//    void setUp()
//    {
//        for(int i = 0; i<10; ++i)
//            fakeDb.push_back(Record(i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8));
//    }

//protected:
//    std::vector<Record> fakeDb;
//};

//KTEST_F(DatabseTests, Simple)
//{
//    ExpressionParser parser;
//    TreePrinter tp;
//    try
//    {
//        Node* mainNode = parser.parseExpression("b==6 and e==15");
//        mainNode->visit(&tp);
//        delete mainNode;
//    }
//    catch(const char* ex)
//    {
//        KTEST_LOG << ex << std::endl;
//        ASSERT_EQ(0,1, "I CATCHED ERROR FOR SOME REASON");
//    }
//}

//class SimpleTest : public ktest::Test
//{
//public:
//    void runTestCase(std::string const& expression)
//    {
//        try
//        {
//            Node* mainNode = parser.parseExpression(expression);
//            mainNode->visit(&tp);
//            delete mainNode;
//        }
//        catch(const char* ex)
//        {
//            KTEST_LOG << ex << std::endl;
//            ASSERT_EQ(0,1, "I CATCHED ERROR FOR SOME REASON");
//        }
//    }

//protected:
//    ExpressionParser parser;
//    TreePrinter tp;
//};

//KTEST_F(SimpleTest, NoBrackets)
//{
//    runTestCase("b==4 or e==7 and f>7");
//}

//KTEST_F(SimpleTest, WithBrackets)
//{
//    runTestCase("a==0 and (b==4 or e==7) and f>7");
//}

//KTEST_F(SimpleTest, WithMultipleNonNestedBrackets)
//{
//    runTestCase("(a==0 or a==9) and (b==4 or e==7) and f>7");
//}

//KTEST_F(SimpleTest, WithNestedBrackets)
//{
//     runTestCase("(h>7 or (a==0 and (b==4 or e==7))) and f>7");
//}
