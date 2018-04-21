//
// Created by HP on 4/21/2018.
//


#include "OpGroups.h"
class OpGroup2 : public OpGroups {


    OpGroup2::size = 2 ;
    bool checkOperand(string currentOperand){

        string s = "^([AXSTFB]|[axstfb])\\,([AXSTFB]|[axstfb])$";

            regex m (s);
            if (regex_match(currentOperand , m)){
                return true ;
            }
        return false;

    }


};