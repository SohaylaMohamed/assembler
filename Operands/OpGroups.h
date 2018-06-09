//
// Created by HP on 4/21/2018.
//
#include <string>
#include <iostream>
#include <string>
#include <regex>


#ifndef ASSEMBLERPASS1_OPGROUPS_H
#define ASSEMBLERPASS1_OPGROUPS_H

class OpGroups {
protected:
     int size;

public:
        int getSize();
    virtual bool checkOperand(std::string currentOperand,  std::string operation) = 0;
};


#endif //ASSEMBLERPASS1_OPGROUPS_H
