//
// Created by HP on 4/21/2018.
//


#include "OpGroups.h"
class OpGroup3 : public OpGroups {


    OpGroup3::size = 1 ;
    bool checkOperand(string currentOperand){

        string s = "^$";

        regex m (s);
        if (regex_match(currentOperand , m)){
            return true ;
        }
        return false;

    }


};