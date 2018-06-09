//
// Created by HP on 4/24/2018.
//

#include "OpGroup3.h"

using namespace std ;
OpGroup3::OpGroup3() {
    size = 2 ;

}
std::string OpGroup3::getOperationObCode(std::string operation) {}
bool OpGroup3::checkOperand(std::string currentOperand, std::string operation) {

    string s = "^([AXSFLBaxslfb])$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}