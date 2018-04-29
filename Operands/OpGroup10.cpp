//
// Created by HP on 4/24/2018.
//

#include "OpGroup10.h"

using namespace std ;

OpGroup10::OpGroup10() {
    size = 0 ;
}
bool OpGroup10::checkOperand(string currentOperand){

    string s = "^\\*|([A-Za-z0-9\\$]{1,8})$";

    regex m (s);
    return regex_match(currentOperand , m) ;

}