//
// Created by c1356 on 2023/3/16.
//
#ifndef PARSER_TOKEN_H
#define PARSER_TOKEN_H

#include <cstring>
#include <iostream>
#include <map>

typedef std::string Tt;

class token {
public:
    static std::map<std::string, Tt> keywords;

    token(Tt type, std::string literal) : type(type), literal(literal) {};

    Tt static LookupIdent(std::string ident);

    static std::string ILLEGAL;
    static std::string E0F;
// Identifiers + literals
    static std::string IDENT;// add, foobar, x, y, ...
    static std::string INT;// 1343456
// Operators
    static std::string ASSIGN;
    static std::string PLUS;
    static std::string MINUS;
    static std::string BANG;
    static std::string ASTERISK;
    static std::string SLASH;

    static std::string LT;
    static std::string GT;

    static std::string EQ;
    static std::string NOT_EQ;

// Delimiters
    static std::string COMMA;
    static std::string SEMICOLON;

    static std::string LPAREN;
    static std::string RPAREN;
    static std::string LBRACE;
    static std::string RBRACE;

// Keywords
    static std::string FUNCTION;
    static std::string LET;
    static std::string TRUE;
    static std::string FALSE;
    static std::string IF;
    static std::string ELSE;
    static std::string RETURN;

    void static init();


public:
    Tt type;
    std::string literal;

};


#endif //PARSER_TOKEN_H
