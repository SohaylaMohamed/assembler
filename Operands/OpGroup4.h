//
// Created by HP on 4/24/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP4_H
#define ASSEMBLERPASS1_OPGROUP4_H


#include "OpGroups.h"

class OpGroup4 : public OpGroups{
public:
    OpGroup4();
    bool checkOperand(std::string currentOperand) override ;


};


#endif //ASSEMBLERPASS1_OPGROUP4_H
