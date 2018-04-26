//
// Created by HP on 4/21/2018.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "Operations.h"

Operations::Operations() {
    Operations::readOperations();
}

int Operations::readOperations() {

    std::string line ;
    ifstream myfile ("operations.txt");
    if(myfile){

        istringstream iss(line);
        std::vector<std::string> result ;
        for(std::string s; iss >> s; )
            result.push_back(s);

        OpGroups *group ;
       if(result.at(1) == "m"){
           OpGroup1
           group =
           operations[result.at(0)] = group;
       }
    }

}
OpGroups Operations::*checkOperation(string key) {
    OpGroups result = operations.find(key);
    if(result == operations.end()){
        operations.erase(key);
        return NULL;
    } else {
        return &operations[key];
    }

}
