//
// Created by LENOVO on 21/04/2018.
//
#include <iostream>
#include "Line.h"
#include "Operations.h"
using namespace std;
#include "LinesConfiguration.h"
void LinesConfiguration::configureLines(vector<vector> lines) {
    for (int i = 0; i <lines.size() ; ++i) {

    }
}
void LinesConfiguration::checkLine(vector<string> line) {
    Line tempLine;
    Operations operations;

    if (line[line.size()-1].find_first_of('*')!= -1){
        tempLine.setComment(line[line.size()-1]);
        if (line.size()-1 == 1){
            if (line[0].find_first_of('.')!= -1){
                tempLine.setComment(line[0]);
            }
            else
                tempLine.setOpCode(line[0]);
        }
        else if (line.size()-1 == 2){
            if(operations.checkOperation(line[0]) == NULL){
                tempLine.setLabel(line[0]);
                if (operations.checkOperation(line[1]) == NULL)
                    tempLine.setOpCode("NOTVALID");
                else
                    tempLine.setOpCode(line[1]);
            }
            else {
                tempLine.setOpCode(line[0]);
                OpGroups *opGroups = operations.checkOperation(line[0]);
                if((*opGroups).checkOperand(line[1])){
                    tempLine.setOperand(line[1]);
                }
                else
                    tempLine.setOperand("NOTVALID");
            }
        }
        else if(line.size()-1 == 3){
            tempLine.setLabel(line[0]);
            if(operations.checkOperation(line[1]) == NULL){
                tempLine.setOpCode("NOTVALID");
                tempLine.setOperand(line[2]);

            }
            else {
                tempLine.setOpCode(line[1]);
                OpGroups *opGroups = operations.checkOperation(line[1]);
                if((*opGroups).checkOperand(line[2])){
                    tempLine.setOperand(line[2]);
                }
                else
                    tempLine.setOperand("NOTVALID");
            }
        }
    }
    lines.p
}