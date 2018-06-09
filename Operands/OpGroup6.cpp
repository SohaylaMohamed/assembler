//
// Created by HP on 4/24/2018.
//


#include "OpGroup6.h"
using namespace std ;
 OpGroup6::OpGroup6() {
   size = 1 ;
}
std::string OpGroup6::getOperationObCode(std::string operation) {}

bool OpGroup6::checkOperand(std::string currentOperand, std::string operation) {


    string s = "^$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}