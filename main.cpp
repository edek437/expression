#include <iostream>
#include <ktest/ktest.hpp>

int main()
{
    bool result = KTEST_RUN_ALL();
    if(result)
        std::cout<<"ALL TESTS PASSED"<<std::endl;
    else
        std::cout<<"SOME TESTS FAILED"<<std::endl;
    return 0;
}
