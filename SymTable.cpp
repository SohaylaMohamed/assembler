//
// Created by LENOVO on 29/04/2018.
//

using namespace std;
#include "SymTable.h"

void SymTable::createSymTable(vector<Line> configuredLines) {
    for (int i = 0; i < configuredLines.size(); ++i) {
        if ((!configuredLines[i].getLabel().empty()) && !findElement(configuredLines[i].getLabel())){
            symTable[configuredLines[i].getLabel()]=configuredLines[i].getAddress();
        }
    }
}
bool SymTable::findElement(string name){
    map<string,string>::const_iterator it =symTable.find(name);
    return it!=symTable.end();
}
