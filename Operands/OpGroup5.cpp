//
// Created by HP on 4/24/2018.
//

#include "OpGroup5.h"

using namespace std ;
OpGroup5::OpGroup5() {

    OpGroup5::size = 2 ;
}
bool checkOperand(string currentOperand){

    string s = "^([AXSFTB]|[axstfb])//,//d+$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}