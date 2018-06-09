//
// Created by HP on 4/24/2018.
//

#include <fstream>
#include "OpGroup3.h"

using namespace std ;
OpGroup3::OpGroup3() {
    size = 2 ;

    std::string line ;
    ifstream myfile ;
    myfile.open("format1");
    if(myfile.is_open()){

        while (getline(myfile , line )){
            istringstream istringstream1 (line);
            vector<string> result ;
            for (string string1 ; istringstream1 >> string1;){
                result.push_back(string1);
            }
            obcode[result[0]] = result[1];
        }


    }

}

bool OpGroup3::checkOperand(std::string currentOperand, std::string operation) {

    string s = "\0";

    regex m (s);
    if (regex_match(currentOperand , m)){
        return true ;
    }
    return false;

}
std::string OpGroup3::getOperationObCode(std::string operation) {
    stringstream ss;
    ss << hex << operation;
    unsigned n;
    ss >> n;
    bitset<8> bit(n);
    return bit.to_string();
}