//
// Created by HP on 4/24/2018.
//

#include "OpGroup5.h"

using namespace std ;
OpGroup5::OpGroup5() {

    size = 0;
    operationsList["WORD"] = 1 ;
    operationsList["BYTE"] = 2 ;
}
std::string OpGroup5::getOperationObCode(std::string operation) {}
bool OpGroup5::checkOperand(std::string currentOperand, std::string operation) {

    int check = operationsList[operation];
    vector<string> array ;
    switch (check) {
        case 1:
            array = {"^[0-9]{1,4}$" , "^-[0-9]{1,4}$" , "^([0-9]{1,4},)+[0-9]{1,4}$"};
            break;
        case 2:
            array = {"^[Cc]'[0-9a-zA-Z]{0,15}'$", "^[xX]'[0-9a-fA-F]{0,14}'$"};
            break;
    }
    int size = array.size();
    for (int i = 0; i < size ;i++) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
        return false;

    }

