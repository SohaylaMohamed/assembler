//
// Created by HP on 4/24/2018.
//
#include "OpGroup2.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


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
            obcode[result[0]] = result[2];


        }
    }


}


bool OpGroup2::checkOperand(std::string currentOperand, std::string operation) {
    if (currentOperand.length() > 18) {
        return false;
    }

    int check = operationsList[operation];
    string string1;
    switch (check) {

        case 1:
            string1 = "^([AXSLFBaxslfb])\\,([AXSLFBaxslfb])$";
            break;
        case 2:
            string1 = "^([AXSLFBaxslfb])$";
            break;
        case 3:
            string1 = "^([AXSFTBaxstfb])//,[0-9]{1,4}$";
            break;
        case 4:
            string1 = "[0-9]{1,4}$";
        default:
            break;

    }
        regex m(string1);
        if (regex_match(currentOperand, m)) {
            return true;

    }
    return false;
}

std::string OpGroup2::getOperationObCode(std::string operation) {
    stringstream ss;
    ss << hex << operation;
    unsigned n;
    ss >> n;
    bitset<8> bit(n);
    return bit.to_string();
}


