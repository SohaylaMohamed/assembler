//
// Created by HP on 4/27/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP7_H
#define ASSEMBLERPASS1_OPGROUP7_H


#include "OpGroups.h"

class OpGroup7 : public OpGroups {
    // start operand
public:
    OpGroup7();
   bool checkOperand(std::string currentOperand ,  std::string operation) override ;



};


#endif //ASSEMBLERPASS1_OPGROUP7_H
