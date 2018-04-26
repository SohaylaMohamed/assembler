//
// Created by HP on 4/21/2018.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "Operations.h"
#include "Operands/OpGroup1.h"
#include "Operands/OpGroup2.h"
#include "Operands/OpGroup3.h"
#include "Operands/OpGroup4.h"
#include "Operands/OpGroup5.h"
#include "Operands/OpGroup6.h"
#include <Operands/OpGroup1.cpp>
Operations::Operations() {
    Operations::readOperations();
}

void Operations::readOperations() {

    std::string line ;
    ifstream myfile ("operations.txt");
    if(myfile){

        istringstream iss(line);
        std::vector<std::string> result ;
        for(std::string s; iss >> s; )
            result.push_back(s);

        OpGroups *group ;
        string  operand  = result.at(1);
       if(operand == "m"){
           group = new OpGroup1();
       } else if (operand == "r1,r2"){
            group = new OpGroup2 ;
       }else if (operand == "r1"){
           group = new OpGroup3 ();
       } else if (operand == "n"){
           group = new OpGroup4();
       }else if (operand == "r1,n"){
           group = new OpGroup5();
       } else if (operand == NULL){
           group = new OpGroup6();
       }
        operations[result.at(0)] = group;

    }

}
OpGroups* Operations::checkOperation(string key) {
    OpGroups result = operations.find(key);
    if(result == operations.end()){
        operations.erase(key);
        return NULL;
    } else {
        return &operations[key];
    }
}