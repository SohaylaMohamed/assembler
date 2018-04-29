//
// Created by HP on 4/24/2018.
//


#include "OpGroup6.h"
using namespace std ;
 OpGroup6::OpGroup6() {
   size = 1 ;
}

bool OpGroup6::checkOperand(std::string currentOperand) {

    string s = "^$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}