//
// Created by HP on 4/24/2018.
//

#include "OpGroup8.h"

using namespace std ;

OpGroup8::OpGroup8() {
    size = 0 ;
}
bool OpGroup8::checkOperand(std::string currentOperand, std::string operation) {


    string s = "^[0-9]{1,4}$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}