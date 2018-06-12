//
// Created by HP on 4/24/2018.
//
#include "OpGroup1.h"

#include <fstream>

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
            operationsList[result[0]] = x;
            obcode[result[0]] = result[2];


        }
    }


}



bool OpGroup1::checkOperand(std::string currentOperand , std::string operation) {
    if (currentOperand.length() > 18) {
        return false;
    }

    int check = operationsList[operation];
    vector<string> array;
    switch (check) {

        case 1:
            array = {"^(#?|@?)[0-9]{1,4}$", R"(^(\=?)[xX]\'([a-fA-F0-9])+\'$)", "^(\\=?)|(#?|@?)\\*$",
                     R"(^(\=?)[cC]\'([a-zA-Z0-9\s])+\'$)", R"(^(\=?)[Ww]\'([0-9])+\'$)",
                     "^(#?|@?)([a-zA-Z0-9]|\\$){1,8}$",
                     R"(^([a-zA-Z0-9]|\$){1,8}\,[Xx]$)", "^\\*\\,[Xx]$", "([a-zA-Z]+[0-9]*)+\\-[a-zA-Z0-9]+",
                     "([a-zA-Z]+[0-9]*)+\\+[0-9]+",
                     "[0-9]+\\+([a-zA-Z]+[0-9]*)+",
                     R"([0-9]+[\+\-\*\/][0-9]+)"};
            break;
        case 2:
            array = {"^(#?|@?)\\*$", "^(#?|@?)([a-zA-Z0-9]){1,8}$", "^(#?|@?)[0-9]{1,4}$",
                     R"(^([a-zA-Z0-9]|\$){1,8}\,[Xx]$)", "^\\*\\,[Xx]$",
                     R"(^([0-9a-zA-Z]+([\+\-]|[\*\/]))+[0-9a-zA-Z]+$)"};
            break;
        case 3:
            array = {"^(#?|@?)\\*$", "^(#?|@?)([a-zA-Z0-9]){1,8}$", "^(#?|@?)[0-9]{1,4}$",
                     R"(^([a-zA-Z0-9]|\$){1,8}\,[Xx]$)", "^\\*\\,[Xx]$", "^$",
                     R"(^([0-9a-zA-Z]+([\+\-]|[\*\/]))+[0-9a-zA-Z]+$)"};
            break;
        default:
            break;

    }
    int size = array.size();
    for (int i = 0; i < size; i++) {
        regex m(array[i]);
        if (regex_match(currentOperand, m)) {
            return true;
        }
    }
    return false;
}
std::string OpGroup1::getOperationObCode(std::string operation) {
    stringstream ss;
    ss << hex << obcode[operation];
    unsigned n;
    ss >> n;
    bitset<8> b(n);
    string result = b.to_string();
    return result;
}

void OpGroup1::setSize(int s) {
    OpGroup1::size = s;
}

