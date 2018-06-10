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



void Operations::readOperations() {

    std::string line;
    ifstream myfile;
    cout<<"before reading";
    myfile.open("operations.txt");
    cout<<"after reading";
        if (myfile.is_open()) {
            cout<<"in condition";
        OpGroups *group1 = new OpGroup1;
            cout<<"Group 1 created";
        OpGroups *group2 = new OpGroup2;
            cout<<"Group 2 created";
        OpGroups *group3 = new OpGroup3;
            cout<<"Group 3 created";
        OpGroups *group5 = new OpGroup5;
            cout<<"Group 5 created";
        OpGroups *group4 = new OpGroup4;

        cout<<"after objects creations ";
        while (getline(myfile, line)) {
            istringstream iss(line);
            std::vector<std::string> result;
            for (std::string s; iss >> s;)
                result.push_back(s);

            if (result.size() == 1) {
                operations[result.at(0)] = group3;
            } else {
                string operand = result.at(1);
                if (operand == "m") {
                    operations[result.at(0)] = group1;
                } else if (operand == "r") {
                    operations[result.at(0)] = group2;
                } else if (operand == "num") {
                    operations[result.at(0)] = group5;
                } else if (operand == "1") {
                    operations[result.at(0)] = group4;
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

