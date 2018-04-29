//
// Created by HP on 4/27/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP10_H
#define ASSEMBLERPASS1_OPGROUP10_H


#include "OpGroups.h"

class OpGroup10 : public OpGroups {
public:
    OpGroup10();
    bool checkOperand(std::string currentOperand) override ;

    // end operator

};


#endif //ASSEMBLERPASS1_OPGROUP10_H
