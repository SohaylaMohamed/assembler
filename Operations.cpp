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
#include "Operands/OpGroup7.h"
#include "Operands/OpGroup8.h"
#include "Operands/OpGroup9.h"
#include "Operands/OpGroup10.h"
#include "Operands/OpGroup11.h"


void Operations::readOperations() {

    std::string line;
    ifstream myfile;
    myfile.open("operations.txt");
    if (myfile.is_open()) {

        OpGroups *group1 = new OpGroup1;
        OpGroups *group2 = new OpGroup2;
        OpGroups *group3 = new OpGroup3;
        OpGroups *group4 = new OpGroup4;
        OpGroups *group5 = new OpGroup5;
        OpGroups *group6 = new OpGroup6;
        OpGroups *group7 = new OpGroup7;
        OpGroups *group8 = new OpGroup8;
        OpGroups *group9 = new OpGroup9;
        OpGroups *group10 = new OpGroup10;
        OpGroups *group11 = new OpGroup11;

        while (getline(myfile, line)) {
            istringstream iss(line);
            std::vector<std::string> result;
            for (std::string s; iss >> s;)
                result.push_back(s);

            if (result.size() == 1) {
                operations[result.at(0)] = group6;
            } else {
                string operand = result.at(1);
                if (operand == "m") {
                    operations[result.at(0)] = group1;
                } else if (operand == "r1,r2") {
                    operations[result.at(0)] = group2;
                } else if (operand == "r1") {
                    operations[result.at(0)] = group3;
                } else if (operand == "n") {
                    operations[result.at(0)] = group4;
                } else if (operand == "r1,n") {
                    operations[result.at(0)] = group5;
                } else if (operand == "a") {
                    operations[result.at(0)] = group7;
                } else if (operand == "num") {
                    operations[result.at(0)] = group8;
                } else if (operand == "h") {
                    operations[result.at(0)] = group9;
                } else if (operand == "e") {
                    operations[result.at(0)] = group10;
                } else if (operand == "l") {
                    operations[result.at(0)] = group11;
                }
            }
        }

    }
}
    OpGroups *Operations::checkOperation(string key) {

    bool  flag = false;
    if(key.find_first_of('+') != -1){
        key = key.substr(1 , key.size() - 1);
        flag = true;
    }
        std::map<string, OpGroups*>::iterator it;
        it = operations.find(key);
        if (it == operations.end()) {
            operations.erase(key);
            return NULL;
        } else {
            if (flag) {
                if (it->second->getSize() == 3)
                    ((OpGroup1*) it->second)->setSize();
                else {
                    return NULL;
                }
            }
            return it->second;


        }
}

