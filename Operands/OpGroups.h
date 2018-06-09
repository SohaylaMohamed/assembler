//
// Created by HP on 4/21/2018.
//


#ifndef ASSEMBLERPASS1_OPGROUPS_H

#define ASSEMBLERPASS1_OPGROUPS_H
#include <string>
#include <iostream>
#include <string>
#include <regex>
#include <map>
using  namespace std ;
class OpGroups {
protected:
     int size;
    map <string , int > operationsList ;
    map <string , string > obCode ;

public:
        int getSize();
    virtual bool checkOperand(std::string currentOperand,  std::string operation) = 0;
};


#endif //ASSEMBLERPASS1_OPGROUPS_H
