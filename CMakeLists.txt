project(Expresion)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCES
    main.cpp
    ExpressionParser.hpp
    ExpressionParser.cpp
    ExpressionParserTests.cpp
    NodeStructs.hpp
    TreePrinter.hpp
    TreePrinter.cpp
)


add_executable(${PROJECT_NAME} ${SOURCES})
#target_link_libraries(${PROJECT_NAME} ktest dl)
