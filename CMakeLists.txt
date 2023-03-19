cmake_minimum_required(VERSION 3.23)
project(MyInterpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyInterpreter
        main.cpp
        token/token.h
        token/token.cpp
        lexer/parser.h
        lexer/parser.cpp
        repl/repl.cpp
        repl/repl.h
        ast/ast.cpp
        ast/ast.h)
