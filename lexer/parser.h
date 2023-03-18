//
// Created by c1356 on 2023/3/16.
//
#include <iostream>
#include <string.h>
#include "../token/token.h"

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H
using namespace std;

class parser {
private:
    std::string input;
    int position = 0;
    int readPosition = 0;
    char ch = -1;
public:
    parser() {
        std::string input;
        int position = 0;      // current position in input (points to current char)
        int readPosition = 0 ;  // current reading position in input (after current char)
        char ch = -1;
    }
    parser(string input):input(input) {
    };
    parser New(string input);

    void readChar();

    token* NextToken();

    char peekChar();

    std::string readIdentifier();

    std::string readNumber();

    bool isLetter(char ch);

    bool isDigit(char ch);

    token* newToken(Tt tokentype, char ch);
    token* newToken(Tt tokentype, std::string ch);
    void skipWhitespace();
};


#endif //PARSER_PARSER_H
