//
// Created by HP on 4/21/2018.
//
#include <string>
#include <iostream>
#include <string>
#include <regex>

#ifndef ASSEMBLERPASS1_OPGROUPS_H
#define ASSEMBLERPASS1_OPGROUPS_H

using namespace std ;
class OpGroups {
protected:
    int size;
public:
    int getSize();
    void setSize(int size);
    virtual bool checkOperand(string currentOperand);





};


#endif //ASSEMBLERPASS1_OPGROUPS_H
