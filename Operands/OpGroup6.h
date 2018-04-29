//
// Created by HP on 4/24/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP6_H
#define ASSEMBLERPASS1_OPGROUP6_H


#include "OpGroups.h"

class OpGroup6 : public OpGroups{

public:
    OpGroup6();
    bool checkOperand(std::string currentOperand) override ;

};


#endif //ASSEMBLERPASS1_OPGROUP6_H
