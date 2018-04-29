//
// Created by HP on 4/24/2018.
//

#include "OpGroup5.h"
#include "OpGroup7.h"

using namespace std ;
OpGroup7::OpGroup7() {

    size = 0 ;
}
bool OpGroup7::checkOperand(std::string currentOperand) {

    string s = "^([a-fA-F0-9]){1,4}$";

    regex m (s);
    return regex_match(currentOperand , m);

}