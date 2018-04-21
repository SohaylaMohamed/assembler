//
// Created by HP on 4/21/2018.
//


#include "OpGroups.h"
class OpGroup4 : public OpGroups {


    OpGroup4::size = 2 ;
    bool checkOperand(string currentOperand){

        string s = "^//d+$";

        regex m (s);
        if (regex_match(currentOperand , m)){
            return true ;
        }
        return false;

    }


};