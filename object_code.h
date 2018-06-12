//
// Created by HP on 6/9/2018.
//

#ifndef ASSEMBLERPASS1_OBJECT_CODE_H
#define ASSEMBLERPASS1_OBJECT_CODE_H


#include <string>
#include <bitset>
#include "Line.h"
#include "SymTable.h"
#include "Operations.h"
#include "Registers.h"
#include "Literal.h"

class object_code {
protected:

    std::bitset<12> toBinary(string hexa);
    string toHex(string binary, int bits);
    Operations operations;
    SymTable symTable;
    Registers registers;
public:
    object_code(SymTable symTable1, map<string, Literal> litab);

    std::string getObject_1(Line line);
   std::string getObject_2(Line line);
   std::string getObject_3(Line line);

    std::vector<string> getObject_dir(Line line);

    map<string, Literal> litab;
    std::string getObject_lit(Line line);

    bool pc_check_bounds(int TA);


    int get_Base();

    bool b_check_bounds(int ta);

    bool base_Exist();

    string NumberToString(int Number);


    string decToBinary(int n);

    int toInt(string number);

    int getTargetAddress(string address, string locationCounter, string base);

    string charToHex(string ch);
};


#endif //ASSEMBLERPASS1_OBJECT_CODE_H
