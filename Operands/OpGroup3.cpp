//
// Created by HP on 4/24/2018.
//

#include "OpGroup3.h"

using namespace std ;
OpGroup3::OpGroup3() {
    size = 2 ;

}
inline bool checkOperand(string currentOperand){

    string s = "^([AXSFLB]|[axslfb])$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}