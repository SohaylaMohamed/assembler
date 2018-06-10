//
// Created by Sohayla Mohamed on 09/06/2018.
//

#ifndef ASSEMBLERPASS1_REGISTERS_H
#define ASSEMBLERPASS1_REGISTERS_H


#include <string>
#include <map>

using namespace std;

class Registers {
protected:
    map<string, int> regNum;
public:
    void readRegisters();
    int getRegNum(string r);

};


#endif //ASSEMBLERPASS1_REGISTERS_H
