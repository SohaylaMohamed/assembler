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
bool OpGroup9::checkOperand(std::string currentOperand, std::string operation) {


    string s = "(^[xX]\\'([a-fA-F0-9]){1,14}\\'$)|(^[cC]\\'([a-zA-Z0-9\\s]){1,15}\\'$)";

    regex m (s);
    return regex_match(currentOperand , m);

}