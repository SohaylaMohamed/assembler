//
// Created by LENOVO on 29/04/2018.
//

using namespace std;
#include "SymTable.h"

vector<Line> SymTable::createSymTable(vector<Line> configuredLines) {
    for (int i = 0; i < configuredLines.size(); ++i) {
        if ((!configuredLines[i].getLabel().empty()) && !findElement(configuredLines[i].getLabel())) {
            if (configuredLines[i].getLabel()!="*")
            {
                symTable[configuredLines[i].getLabel()] = configuredLines[i].getAddress();
                symTableType[configuredLines[i].getLabel()] = true;
            }
        }
        if (configuredLines[i].getOpCode() == "EQU")
        {
            if (findElement(configuredLines[i].getOperand()) && configuredLines[i].getOperand()!= "*" )
            {
                symTable[configuredLines[i].getLabel()] = symTable[configuredLines[i].getOperand()];
            }
            else if (configuredLines[i].getOperand()== "*")
            {
                symTable[configuredLines[i].getLabel()] = configuredLines[i].getAddress();
            }
            else
                configuredLines[i].setError("***** Operand Not Predefined");
        }
    }
    return configuredLines;
}
bool SymTable::findElement(string name){
    map<string,string>::const_iterator it =symTable.find(name);
    return it!=symTable.end();
}

string SymTable::getElementAddress(string name) {
    map<string, string>::const_iterator it = symTable.find(name);
    cout << name;
    if (it == symTable.end()) {
        return NULL;
    } else {
        return it->second;
    }
}
