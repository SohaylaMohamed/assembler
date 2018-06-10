//
// Created by LENOVO on 29/04/2018.
//
#include <map>
#include <string>
#include <vector>
#include "Line.h"
#ifndef ASSEMBLERPASS1_SYMTABLE_H
#define ASSEMBLERPASS1_SYMTABLE_H

using namespace std;

class SymTable {
public:
    vector<Line> createSymTable(vector<Line> configuredLines);

    map <string, string> symTable;

    bool findElement(string name);

    string getElementAddress(string name);
};


#endif //ASSEMBLERPASS1_SYMTABLE_H
