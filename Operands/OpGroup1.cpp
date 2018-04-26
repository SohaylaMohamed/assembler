//
// Created by HP on 4/24/2018.
//

#include "OpGroups.h"

using namespace std ;
class OpGroup1 : public OpGroups {

OpGroup1::OpGroup1() {
    OpGroup1::size = 3;
}

bool checkOperand(std::string currentOperand) {
    string array[] = {"^#\\d+$", "^\\*$", "^\\w+$", "^\\d$"};
    for (int i = 0; i < array->size(); ++i) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
    return false;
}

};