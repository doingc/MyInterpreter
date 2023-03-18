#include "lexer/parser.h"
#include "token/token.h"
#include "repl/repl.h"
#include <iostream>
using namespace std;
int main(){
    std::cout<<">>>>please try it"<<endl;
    cout<<token::keywords.contains("LET");
    Repl re;

    re.start();
    cout<<token::keywords.contains("LET");


}