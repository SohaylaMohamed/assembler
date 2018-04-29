//
// Created by HP on 4/27/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP8_H
#define ASSEMBLERPASS1_OPGROUP8_H


#include "OpGroups.h"

class OpGroup8 : public OpGroups
{
public:
    OpGroup8();
    bool checkOperand(std::string currentOperand) override ;

};


#endif //ASSEMBLERPASS1_OPGROUP8_H
