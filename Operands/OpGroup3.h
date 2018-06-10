//
// Created by HP on 4/24/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP3_H
#define ASSEMBLERPASS1_OPGROUP3_H


#include "OpGroups.h"

class OpGroup3 : public OpGroups {

public:
OpGroup3();

    bool checkOperand(std::string currentOperand ,  std::string operation) override ;
    std::string getOperationObCode(std::string operation) override;



};


#endif //ASSEMBLERPASS1_OPGROUP3_H
