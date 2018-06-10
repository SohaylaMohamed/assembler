//
// Created by Sohayla Mohamed on 29/04/2018.
//

#include "OpGroup11.h"
using namespace std ;

OpGroup11::OpGroup11() {
    size = 0 ;
}
bool OpGroup11::checkOperand(string currentOperand,std::string operation){

    string s = "^([0-9]{1,4})|([A-Za-z0-9\\$]{1,8})$";
    regex m (s);
    return regex_match(currentOperand , m) ;

}


