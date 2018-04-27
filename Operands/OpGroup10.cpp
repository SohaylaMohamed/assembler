//
// Created by HP on 4/24/2018.
//

#include "OpGroup10.h"

using namespace std ;

OpGroup10::OpGroup10() {
    size = 0 ;
}
inline bool checkOperand(string currentOperand){

    string s = "(^$)|(^*$)|(^[A-Za-z]+$)|(^[0-9]+$)";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}