//
// Created by HP on 4/21/2018.
//

#include "Operations.h"

Operations::Operations() {
    Operations::readOperations();
}

int Operations::readOperations() {

    //read operations file

}
OpGroups Operations::checkOperation(string key) {

    OpGroups result = operations.find(key);
    if(result == operations.end()){
        operations.erase(key);
        return NULL;
    } else {
        return operations[key];
    }

}