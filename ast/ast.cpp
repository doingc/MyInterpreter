//
// Created by c1356 on 2023/3/17.
//

#include "ast.h"
std::vector<std::string> ast::tokenliteral(){
    if(this->statements.size() > 0){
        return statements;
    }
    else return std::vector<std::string>{{""}};
};