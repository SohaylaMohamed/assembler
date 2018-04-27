//
// Created by HP on 4/24/2018.
//
#include "OpGroup1.h"

using namespace std ;


 OpGroup1::OpGroup1() {
     size = 3;
}

    inline bool checkOperand(std::string currentOperand) {
        string array[] = {"^#\\d+$","^[x]|[X]\\'([abcdef]|[ABCDEF]|[0-9])+\\'$" "^\\*$", "^[c]|[C]\\'([a-zA-Z0-9])+\\'$","^([a-zA-Z]||[0-9])+$", "^#([a-zA-Z]||[0-9])+$", "^\\d+$"};
    for (int i = 0; i < 6 ; ++i) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
    return false;
}

