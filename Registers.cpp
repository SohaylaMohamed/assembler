//
// Created by Sohayla Mohamed on 09/06/2018.
//
#include "Registers.h"
#include <fstream>
#include <sstream>
#include <vector>

 void Registers::readRegisters() {
    std::string line;
    ifstream file;
    file.open("registers.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            std::vector<std::string> result;
            for (std::string s; iss >> s;)
                result.push_back(s);
            stringstream geek(result[1]);
            int x = 0;
            geek >> x;
            Registers::regNum[result[0]] = x;
        }
    }
}

int  Registers::getRegNum(string r) {
    return regNum[r];
}
