//
// Created by HP on 4/24/2018.
//
#include "OpGroup1.h"

using namespace std ;


OpGroup1::OpGroup1() {
    size = 3;
}

bool OpGroup1::checkOperand(std::string currentOperand) {
    string array[] = {"^#\\d+$","^[x]|[X]\\'([abcdef]|[ABCDEF]|[0-9])+\\'$", "^\\*$", "^[cC]\\'([a-zA-Z0-9\\s])+\\'$","^([a-zA-Z]||[0-9])+$", "^#([a-zA-Z]||[0-9])+$", "^\\d+$"};
    for (int i = 0; i < 6 ; ++i) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
    return false;
}

