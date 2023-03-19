//
// Created by c1356 on 2023/3/16.
//
#include "parser.h"

parser parser::New(string input) {
    std::cout<<"你输入的是:"<<input<<std::endl;
    this->input = input;
    parser p(input) ;
    return p;
}

void parser::readChar() {
    if (readPosition >= input.size()) {
        ch = 0;
    } else {
        ch = input[readPosition];
    }
    position = readPosition;
    readPosition++;
}

token* parser::NextToken() {
    token *tok;
    skipWhitespace();
    switch (ch) {
        case '=':
            if (peekChar() == '=') {
                char t_ch = ch;
                readChar();
                string s = to_string(t_ch) + to_string(ch)  ;
                tok = new token(token::EQ, s);
            } else {
                tok = newToken(token::ASSIGN, ch);
            }
            break;
        case '+':
            tok = newToken(token::PLUS, ch);
            break;
        case '-':
            tok = newToken(token::MINUS, ch);
            break;
        case '!':
            if (peekChar() == '=') {
                char p = ch;
                readChar();
                std::string r = to_string(p)  + to_string(ch);
                tok = new token(token::NOT_EQ, r);
            } else {
                tok = newToken(token::BANG, ch);
            }
            break;
        case '/':
            tok = newToken(token::SLASH, ch);
            break;
        case '*':
            tok = newToken(token::ASTERISK, ch);
            break;
        case '<':
            tok = newToken(token::LT, ch);
            break;
        case '>':
            tok = newToken(token::GT, ch);
            break;
        case ';':
            tok = newToken(token::SEMICOLON, ch);
            break;
        case ',':
            tok = newToken(token::COMMA, ch);
            break;
        case '{':
            tok = newToken(token::LBRACE, ch);
            break;
        case '}':
            tok = newToken(token::RBRACE, ch);
            break;
        case '(':
            tok = newToken(token::LPAREN, ch);
            break;
        case ')':
            tok = newToken(token::RPAREN, ch);
            break;
        case 0:
            tok = newToken(token::E0F, ' ');
            break;
        default:
            if (isLetter(ch)) {
                string s = readIdentifier();
                Tt Type = token::LookupIdent(s);
                return newToken(Type, s);
            } else if (isDigit(ch)) {
                string s = readNumber();
                return newToken(token::INT, s);
            } else {

                tok = newToken(token::ILLEGAL, ch);
            }
    }
    readChar();
    return tok;
}


char parser::peekChar() {
    if (readPosition >= input.size()) {
        return 0;
    } else {
        return input[readPosition];
    }
}

std::string parser::readIdentifier() {
    int pos = position;
    while (isLetter(ch)) {
        readChar();
    }
    return input.substr(pos, position-pos);
}

std::string parser::readNumber() {
    int pos = position;
    while (isDigit(ch)) {
        this->readChar();
    }
    return input.substr(pos, position-pos);
}

bool parser::isLetter(char ch) {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

bool parser::isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

token* parser::newToken(Tt tokentype, char ch) {
    return new token(tokentype, ch + "");
}
token* parser::newToken(Tt tokentype, std::string ch) {
    return new token(tokentype, ch );
}
void parser::skipWhitespace() {
    while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == -1) {
        readChar();
    }
}