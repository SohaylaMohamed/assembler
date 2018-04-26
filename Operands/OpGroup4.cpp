//
// Created by HP on 4/24/2018.
//

#include "OpGroup4.h"
using namespace std ;

OpGroup4::OpGroup4() {

    OpGroup4::size = 2 ;

}
bool checkOperand(string currentOperand){

    string s = "^//d+$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}

