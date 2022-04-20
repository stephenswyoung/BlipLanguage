//
// Created by ssy30 on 11/27/2021.
//

#include "database.h"
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "Parse.h"

void database::addComment(std::string newComment) {
    vComment.push_back(newComment);
}

void database::addToken(std::string splitToken, TokenType splitTokenType){
    vin.push_back(splitToken);
    vToken.push_back(splitTokenType);
}


void database::printAllDatabase(){
    int i=0;
    while(vin.size()>i){
        std::cout << vin.at(i) << " ";
        i++;
    }
    std::cout << std::endl;
}

void database::printDatabase(int index) {
    std::cout << vin.at(index);
}

void database::newVar(std::string name, std::string val){
    variables.emplace(name, val);
}

void database::changeVar(std::string name, std::string val){
    variables.erase(name);
    variables.emplace(name, val);
}

bool database::isVar(std::string name){
    if(variables.find(name)!=variables.end()){
        return true;
    }
        return false;
}

std::string database::getVal(std::string name){
    return variables[name];
}

std::string database::getToken(int index){
    //std::string test= vin.at(index);
    return vin.at(index);
}

TokenType database::getTokenType(int index){
    return vToken.at(index);
}

//std::string database::getTokenString(int index){
//    std::string tokenStr=vin.sub(index,vin.size());
    

//}

int database::sizeOfDatabase() {
    return vin.size();
}

void database::clearDatabase(){
    variables.clear();
    vin.clear();
    vToken.clear();
}


