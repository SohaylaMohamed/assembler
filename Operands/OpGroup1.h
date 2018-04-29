//
// Created by HP on 4/24/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP1_H
#define ASSEMBLERPASS1_OPGROUP1_H


#include "OpGroups.h"

class OpGroup1 : public OpGroups
{
public:
    OpGroup1();
    bool checkOperand(std::string currentOperand) override ;

};


#endif //ASSEMBLERPASS1_OPGROUP1_H
