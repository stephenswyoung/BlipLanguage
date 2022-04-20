//
// Created by ssy30 on 11/27/2021.
//

#ifndef PROJECT8_DATABASE_H
#define PROJECT8_DATABASE_H
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "Parse.h"
#include <string>


class database {
public:
    void addComment(std::string newComment);
    void addToken(std::string splitToken, TokenType splitTokenType);
    void printAllDatabase();
    void printDatabase(int index);
    void newVar(std::string name, std::string val);
    void changeVar(std::string name, std::string val);
    bool isVar(std::string name);
    std::string getVal(std::string name);
    std::string getToken(int index);
    TokenType getTokenType(int index);
    int sizeOfDatabase();
    void clearDatabase();

private:
        std::vector<std::string> vin;
        std::vector<TokenType> vToken;
        std::map <std::string, std::string> variables;
        std::vector<std::string> vComment;



    };


#endif //PROJECT8_DATABASE_H
