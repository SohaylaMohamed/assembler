//
// Created by HP on 4/24/2018.
//
#include "OpGroup2.h"

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std ;


OpGroup2::OpGroup2() {
    size = 2;

    std::string line;
    ifstream file;
    file.open("g2.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            std::vector<std::string> result;
            for (std::string s; iss >> s;)
                result.push_back(s);

            stringstream geek(result[1]);
            int x = 0;
            geek >> x;
            operationsList[result[0]] = x;
            obCode[result[0]] = result[2];


        }
    }


}



bool OpGroup2::checkOperand(std::string currentOperand , std::string operation) {
    if(currentOperand.length() > 18) {
        return false;
    }

    int check = operationsList[operation];
    vector<string> array;
    switch (check)  {

        case 1:   array = {"^([AXSLFBaxslfb])\\,([AXSLFBaxslfb])$"};
            break;
        case 2:  array = {"^([AXSLFBaxslfb])$"};
            break;
        case 3:  array = {"^([AXSFTBaxstfb])//,[0-9]{1,4}$"};
            break;
        default: break;

    }
    int size = array.size();
    for (int i = 0; i < size; ++i) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
    return false;
}

