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
class object_code {
private:
    std::bitset<12> toBinary(string hexa);

    string toHex(string binary, int bits);
    Operations operations;
    SymTable symTable;
    Registers registers;
public:
    object_code(SymTable symTable1);
   std::string getObject_1(Line line);
   std::string getObject_2(Line line);
   std::string getObject_3(Line line);

    std::vector<string> getObject_dir(Line line);


    bool pc_check_bounds(int TA);


    int get_Base();

    bool b_check_bounds(int ta);

    bool base_Exist();

    string NumberToString(int Number);

    int getTargetAddress(string address, string locationCounter);

    string decToBinary(int n);

    int toInt(string number);
};


#endif //ASSEMBLERPASS1_OBJECT_CODE_H
