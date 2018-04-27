//
// Created by HP on 4/24/2018.
//

#include "OpGroup5.h"
#include "OpGroup7.h"

using namespace std ;
OpGroup7::OpGroup7() {

    size = 0 ;
}
inline bool checkOperand(string currentOperand){

    string s = "^(\\d|[a-zA-Z]){1,5}$";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}