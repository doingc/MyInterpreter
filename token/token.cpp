//
// Created by c1356 on 2023/3/16.
//

#include "token.h"

void token::init() {
    token::keywords["fn"] = token::FUNCTION;
    token::keywords["let"] = LET;
    token::keywords["true"] = TRUE;
    token::keywords["false"] = FALSE;
    token::keywords["if"] = IF;
    token::keywords["else"] = ELSE;
    token::keywords["return"] = RETURN;
}

Tt token::LookupIdent(std::string ident) {
    token::init();
    if (token::keywords.contains(ident)) {
        return token::keywords.find(ident)->second;
    }
    return token::IDENT;
}

std::string token::ILLEGAL = "ILLEGAL";
std::string token::E0F = "EOF";
std::map<std::string, Tt> token::keywords;
// Identifiers + literals
std::string token::IDENT = "IDENT"; // add, foobar, x, y, ...
std::string token::INT = "INT";// 1343456

// Operators
std::string token::ASSIGN = "=";
std::string token::PLUS = "+";
std::string token::MINUS = "-";
std::string token::BANG = "!";
std::string token::ASTERISK = "*";
std::string token::SLASH = "/";

std::string token::LT = "<";
std::string token::GT = ">";

std::string token::EQ = "==";
std::string token::NOT_EQ = "!=";

// Delimiters
std::string token::COMMA = ",";
std::string token::SEMICOLON = ";";

std::string token::LPAREN = "(";
std::string token::RPAREN = ")";
std::string token::LBRACE = "{";
std::string token::RBRACE = "}";

// Keywords
std::string token::FUNCTION = "FUNCTION";
std::string token::LET = "LET";
std::string token::TRUE = "TRUE";
std::string token::FALSE = "FALSE";
std::string token::IF = "IF";
std::string token::ELSE = "ELSE";
std::string token::RETURN = "RETURN";
