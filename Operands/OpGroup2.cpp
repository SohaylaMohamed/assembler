//
// Created by HP on 4/24/2018.
//

#include "OpGroup2.h"

using  namespace std ;
OpGroup2::OpGroup2() {

   this -> size = 2 ;
}
inline bool checkOperand(string currentOperand){

    string s = "^([AXSLFB]|[axslfb])\\,([AXSLFB]|[axslfb])$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}

