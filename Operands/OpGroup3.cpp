//
// Created by HP on 4/24/2018.
//

#include "OpGroup3.h"

using namespace std ;
OpGroup3::OpGroup3() {
    OpGroup3::size = 2 ;

}
bool checkOperand(string currentOperand){

    string s = "^([AXSFTB]|[axstfb])$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}