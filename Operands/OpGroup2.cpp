//
// Created by HP on 4/24/2018.
//

#include "OpGroup2.h"

using  namespace std ;
OpGroup2::OpGroup2() {

    OpGroup2::size = 2 ;
}
bool checkOperand(string currentOperand){

    string s = "^([AXSTFB]|[axstfb])\\,([AXSTFB]|[axstfb])$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}
