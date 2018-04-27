//
// Created by HP on 4/24/2018.
//

#include "OpGroup5.h"
#include "OpGroup8.h"
#include "OpGroup9.h"

using namespace std ;

OpGroup9::OpGroup9() {
    size = 0 ;
}
inline bool checkOperand(string currentOperand){

    string s = "(^C'(([a-zA-Z])|([]0-9))+'$)|(^X'(([a-fA-F])|([0-9]))+'$)";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}