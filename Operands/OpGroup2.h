//
// Created by HP on 4/24/2018.
//
#include <iostream>

#ifndef ASSEMBLERPASS1_OPGROUP2_H
#define ASSEMBLERPASS1_OPGROUP2_H

#include <string>
#include <map>


#include "OpGroups.h"
using  namespace std ;
class OpGroup2 : public OpGroups {
public:
    OpGroup2();
    bool checkOperand(std::string currentOperand ,  std::string operation) override ;


    string getOperationObCode(string operation) override ;
};


#endif //ASSEMBLERPASS1_OPGROUP2_H
