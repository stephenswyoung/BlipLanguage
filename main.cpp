// CRM in C++ <filename.cpp>
// EE 312 Project 8 submission by
// <Stephen Young>
// <ssy397>
// Slip days used: <1>
// Fall 2021


#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include "Parse.h"
#include "database.h"

database blipdb;
std::vector <std::string> parseInput;

int ops(std::string sign, int x, int y){

    if(sign=="+"){
        return (x+y);
    }
    if(sign=="-"){
        return (x-y);
    }
    if(sign=="/"){
        return (x/y);
    }
    if(sign=="*"){
        return (x*y);
    }
    if(sign==">"){
        return (x>y);
    }
    if(sign=="<"){
        return (x<y);
    }
    if(sign=="=="){
        return (x==y);
    }
    if(sign=="!="){
        return (x!=y);
    }
}

int unOps(std::string sign, int x){
    if(sign=="!"){
        return(!x);
    }
    if(sign=="~"){
        x--;
        return(~x);
    }
}

int opsParse(){
    std::string first;
    first=(parseInput.at(0));
    parseInput.erase(parseInput.begin());
    if(blipdb.isVar(first)) {
        first=blipdb.getVal(first);
    }
    if(first.find_first_not_of("0123456789") == std::string::npos) {
            return std::stoi(first);
    }
    if((first=="~")||(first=="!")){
        int argUn = opsParse();
        return unOps(first, argUn);
    }
    int arg1 = opsParse();
    int arg2 = opsParse();
    return ops(first, arg1, arg2);
}

void run() {
    int i = 0;
    TokenType current = next_token_type;
    while (true) {
        if (next_token_type == SYMBOL) {
            std::string commentCheck = next_token();
            if (commentCheck == "//") {
                //while
                //const char *tempC= next_token();
                //char *commentHold= const_cast<char *>(next_token());
                skip_line();
                //read_next_token();
                //char *commentEnd= const_cast<char *>(next_token());
                //while (commentHold!=commentEnd){
                    //blipdb.addComment(commentHold);
                    //commentHold++;
                //}
            }
        }
        const char *p = next_token();
        read_next_token();
        current = next_token_type;
        blipdb.addToken(p, current);
        if (next_token_type == END) {
            break;
        }
    }
    while (i < blipdb.sizeOfDatabase()) {
        if (blipdb.getToken(i) == "text") {
            i++;
            blipdb.printDatabase(i);
        }
        if (blipdb.getToken(i) == "output") {

            i++;
            while ((blipdb.getTokenType(i) == SYMBOL) || (blipdb.getTokenType(i) == NUMBER) || (blipdb.isVar(blipdb.getToken(i)))) {
                std::string testNum = blipdb.getToken(i);
                parseInput.push_back(blipdb.getToken(i));
                if ((blipdb.getTokenType(i + 1) == SYMBOL) || (blipdb.getTokenType(i + 1) == NUMBER) ||(blipdb.isVar(blipdb.getToken(i+1)))) {
                    i++;
                } else {
                    break;
                }
            }
            std::cout << opsParse();
            parseInput.clear();
        }
        if (blipdb.getToken(i) == "var") {
            i++;
            if(blipdb.isVar(blipdb.getToken(i))){
                std::cout << "variable " << blipdb.getToken(i) << " incorrectly re-initialized" << std::endl;
                //break;
            }
            else {
                blipdb.newVar(blipdb.getToken(i), blipdb.getToken(i + 1));
                i++;
            }
        }
        if (blipdb.getToken(i) == "set") {
            i++;
            if (!blipdb.isVar(blipdb.getToken(i))) {
                std::cout << "variable " << blipdb.getToken(i) << " not declared" << std::endl;
            } else {
                int varHold = i;
                i++;
                while ((blipdb.getTokenType(i) == SYMBOL) || (blipdb.getTokenType(i) == NUMBER) ||
                       (blipdb.isVar(blipdb.getToken(i)))) {
                    std::string testNum = blipdb.getToken(i);
                    parseInput.push_back(blipdb.getToken(i));
                    if ((blipdb.getTokenType(i + 1) == SYMBOL) || (blipdb.getTokenType(i + 1) == NUMBER) ||
                        (blipdb.isVar(blipdb.getToken(i + 1)))) {
                        i++;
                    } else {
                        break;
                    }
                }
                blipdb.changeVar(blipdb.getToken(varHold), std::to_string(opsParse()));
                parseInput.clear();
            }
        }
        i++;
    }
    blipdb.clearDatabase();
}


int main() {

    //std::cout<<"Test 4"<<std::endl;
    set_input("test_grader.blip");
    //set_input("test4.blip");
    run();

    //std::cout << std::endl << "Test 2" << std::endl;
    //set_input("test2.blip");
    //run();

    //std::cout << std::endl << "Test 3" << std::endl;
    //set_input("test3.blip");
    //run();

    //std::cout << std::endl << "Test 1" << std::endl;
    //set_input("test1.blip");
    //run();
}
