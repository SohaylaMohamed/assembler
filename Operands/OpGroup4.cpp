//
// Created by HP on 4/24/2018.
//

#include <fstream>
#include "OpGroup4.h"
using namespace std ;

OpGroup4::OpGroup4() {

    size = 2 ;

    string line ;
    ifstream myfile ;
    myfile.open("NO-object-code.txt");
    if (myfile.is_open()){

        while (getline(myfile , line)) {
            istringstream iss(line);
            std::vector<std::string> result;
            for (std::string s; iss >> s;)
                result.push_back(s);

            stringstream geek(result[1]);
            int x = 0;
            geek >> x;
            operationsList[result[0]] = x;

        }
    }

}

std::string OpGroup4::getOperationObCode(std::string operation) {}
bool OpGroup4::checkOperand(std::string currentOperand, std::string operation) {

    if(currentOperand.length() > 18) {
        return false;
    }

    int check = operationsList[operation];
    vector<string >array;
    switch (check)  {

        case 1:   array = {"^[0-9]{1,4}$"};
            break;

        case 2:  array = {"^([a-fA-F0-9]){1,4}$"};
            break;
        case 3:  array = {"^*$","([A-Za-z0-9\\$]{1,8})$" , "\0"};
            break;
        case 4:
            array = {"[0-9a-zA-Z]+$", "([a-zA-Z]+[0-9]*)+\\-[a-zA-Z0-9]+", "([a-zA-Z]+[0-9]*)+\\+[a-zA-Z0-9]+"};
            break;
        case 5: array = {"\0"};
            break;
        case 6: array = {"[0-9a-zA-Z]+$" , "^*$"};
        default: break;

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

