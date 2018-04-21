//
// Created by HP on 4/21/2018.
//


#include "OpGroups.h"
class OpGroup3 : public OpGroups {


    OpGroup3::size = 2 ;
    bool checkOperand(string currentOperand){

        string s = "^([AXSFTB]|[axstfb])//,//d+$";

        regex m (s);
        if (regex_match(currentOperand , m)){
            return true ;
        }
        return false;

    }


};