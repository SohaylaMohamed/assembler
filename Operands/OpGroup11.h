//
// Created by Sohayla Mohamed on 29/04/2018.
//

#ifndef ASSEMBLERPASS1_OPGROUP11_H
#define ASSEMBLERPASS1_OPGROUP11_H

#include "OpGroups.h"

class OpGroup11 : public OpGroups {
public:
    OpGroup11();
    bool checkOperand(std::string currentOperand,std::string operation) override ;
    std::string getOperationObCode(std::string operation) override;


    // end operator

};


#endif //ASSEMBLERPASS1_OPGROUP11_H
