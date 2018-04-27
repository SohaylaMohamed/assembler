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



void Operations::readOperations() {

    std::string line;
    ifstream myfile;
    myfile.open("C:\\Users\\karim\\Desktop\\operations.txt");
    if (myfile.is_open()) {

        while (getline(myfile, line)) {
            istringstream iss(line);
            std::vector<std::string> result;
            for (std::string s; iss >> s;)
                result.push_back(s);

            OpGroups *group;
            if (result.size() == 1) {
                group = new OpGroup6();
            } else {
                string operand = result.at(1);
                if (operand == "m") {
                    group = new OpGroup1();
                } else if (operand == "r1,r2") {
                    group = new OpGroup2;
                } else if (operand == "r1") {
                    group = new OpGroup3();
                } else if (operand == "n") {
                    group = new OpGroup4();
                } else if (operand == "r1,n") {
                    group = new OpGroup5();
                } else if (operand == "a") {
                    group = new OpGroup7();
                } else if (operand == "num") {
                    group = new OpGroup8();
                } else if (operand == "h") {
                    group = new OpGroup9();
                } /*else if (operand == "e") {
                    group = new OpGroup10();
                }*/
            }
            operations[result.at(0)] = *group;
        }

    }
}
    OpGroups *Operations::checkOperation(string key) {
        std::map<string, OpGroups>::iterator it;
        it = operations.find(key);
        if (it == operations.end()) {
            operations.erase(key);
            return NULL;
        } else {
            return &it->second;
        }
    }
