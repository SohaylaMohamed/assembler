//
// Created by HP on 4/21/2018.
//
#include <map>
#include <iostream>
#include "Operands/OpGroups.h"
#include <string>
#ifndef ASSEMBLERPASS1_OPERATIONS_H
#define ASSEMBLERPASS1_OPERATIONS_H

using namespace std ;
class Operations {

protected:
    map <string, OpGroups > operations;
    void readOperations();

public:
    Operations();
    OpGroups *checkOperation(string key);
};


#endif //ASSEMBLERPASS1_OPERATIONS_H
