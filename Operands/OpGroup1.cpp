//
// Created by HP on 4/24/2018.
//
#include "OpGroup1.h"

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std ;


OpGroup1::OpGroup1() {
    size = 3;

    std::string line;
    ifstream file;
    file.open("g1A.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            std::vector<std::string> result;
            for (std::string s; iss >> s;)
                result.push_back(s);

            stringstream geek(result[1]);
            int x = 0;
            geek >> x;
            OpGroup1::opertionsList[result[0]] = x;

        }
    }
}



bool OpGroup1::checkOperand(std::string currentOperand , std::string operation) {
     if(currentOperand.length() > 18) {
         return false;
     }

        int check = OpGroup1::opertionsList[operation];
        vector<string> array;
        switch (check)  {

            case 1:   array = {"^(#?|@?)[0-9]{1,4}$","^(\\=?)[wwWW]\\'([0-9])+\\'$","^(\\=?)[xwXW]\\'([a-fA-F0-9])+\\'$" ,"^\\*$", "^(\\=?)[cwCW]\\'([a-zA-Z0-9])+\\'$", "^(#?|@?)([a-zA-Z]|[0-9]|\\$){1,8}$","^([a-zA-Z]|[0-9]|\\$){1,8}\\,[Xx]$"};
                break;
            case 2:  array = {"^\\*$", "^(#?|@?)([a-zA-Z]||[0-9])+$", "^(#?|@?)[0-9]{1,4}$"};
                break;
            case 3: array = {"^(#?|@?)[0-9]{1,4}$", "^\\*$", "^(#?|@?)([a-zA-Z]|[0-9]|\\$){1,8}$","^([a-zA-Z]|[0-9]|\\$){1,8}\\,[Xx]$"};

                break;
            default: break;

        }
    for (int i = 0; i < 6 ; ++i) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
    return false;
}
void OpGroup1::setSize() {
    OpGroup1::size = 4;
}

