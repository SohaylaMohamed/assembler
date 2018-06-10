//
// Created by HP on 6/9/2018.
//

#ifndef ASSEMBLERPASS1_OBJECT_CODE_H
#define ASSEMBLERPASS1_OBJECT_CODE_H


#include <string>
#include <bitset>
#include "Line.h"
#include "SymTable.h"

class object_code {
private:
    bitset<12> toBinary(string hexa);

    string toHex(string binary);

    SymTable symTable;
public:
    object_code(SymTable symTable1);
   std::string getObject_1(Line line);
   std::string getObject_2(Line line);
   std::string getObject_3(Line line);
   std::string getObject_dir(Line line);


    bool pc_check_bounds(int TA);


    int get_Base();

    bool b_check_bounds(int ta);

    bool base_Exist();
};


#endif //ASSEMBLERPASS1_OBJECT_CODE_H
