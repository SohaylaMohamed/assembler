//
// Created by HP on 4/21/2018.
//
#include <map>
#include <iostream>
#include "OpGroups.h"
#include <string>
#ifndef ASSEMBLERPASS1_OPERATIONS_H
#define ASSEMBLERPASS1_OPERATIONS_H

using namespace std ;
class Operations {

private:

    map <string, OpGroups > operations;
    readOperations();

public:

    Operations();
    OpGroups *checkOperation(string key);




};


#endif //ASSEMBLERPASS1_OPERATIONS_H
