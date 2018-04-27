//
// Created by HP on 4/24/2018.
//

#include "OpGroup8.h"

using namespace std ;

OpGroup8::OpGroup8() {
    size = 0 ;
}
inline bool checkOperand(string currentOperand){

    string s = "^[0-9]+$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}