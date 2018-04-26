//
// Created by HP on 4/24/2018.
//

#include "OpGroups.h"

using namespace std ;
class OpGroup1 : public OpGroups {

 OpGroup1() {
     size = 3;
}

    inline bool checkOperand(std::string currentOperand) {
        string array[] = {"^#\\d+$", "^\\*$", "^([a-zA-Z]||[0-9])+$", "^#([a-zA-Z]||[0-9])+$", "^\\d+$"};
    for (int i = 0; i < 5; ++i) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
    return false;
}

};