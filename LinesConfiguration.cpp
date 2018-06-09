//
// Created by LENOVO on 21/04/2018.
//
#include <iostream>
#include "Line.h"
#include "Operations.h"
#include <ctype.h>

using namespace std;

#include "LinesConfiguration.h"

vector<Line> LinesConfiguration::configureLines(vector<vector<string>> lines) {
    operations.readOperations();
    for (int i = 0; i < lines.size(); ++i) {
        checkLine(lines[i]);
    }
    for (int j = 0; j < configuredLines.size(); ++j) {
        for (int k =j+1 ; k < configuredLines.size(); ++k) {
            if (configuredLines[j].getLabel() == configuredLines[k].getLabel() && (configuredLines[j].getLabel() != "")){
                configuredLines[k].setError("****Error:Sympol\'" + configuredLines[k].getLabel() + "\'already defined");
            }
        }
    }
    return configuredLines;
}

void LinesConfiguration::checkLine(vector<string> line) {
    for (int i = 0; i < line.size(); ++i) {
        for (int j = 0; j < line[i].size(); ++j) {
            (line[i])[j] = toupper((line[i])[j]);
        }
    }
    //TODO handle the error of having repeated label/operation/operand in the same line
    Line tempLine;


    if (line[line.size() - 1].find_first_of('*') != -1) {
        tempLine.setComment(line[line.size() - 1]);
        line.pop_back();
    }else {
        tempLine.setComment("");
    }
        if (line.size()  == 1) {
            if (line[0].find_first_of('.') != -1) {
                tempLine.setComment(line[0]);
            } else {
                    tempLine.setOpCode(line[0]);
            }
        } else if (line.size()  == 2) {
            if (!operations.checkOperation(line[0])) {
                tempLine.setLabel(line[0]);
                if (!operations.checkOperation(line[1])) {
                    tempLine.setOpCode(line[1]);
                    tempLine.setError("***** unrecognized operation code");
                }
                else {
                    tempLine.setOpCode(line[1]);
                }
            } else {
                tempLine.setOpCode(line[0]);
                if(line[0].find_first_of('+') != -1 )
                    line[0] = line[0].substr(1 , line[0].size() - 1);
                OpGroups *opGroups = operations.checkOperation(line[0]);

                if ((*opGroups).checkOperand(line[1] , line[0])) {
                    tempLine.setOperand(line[1]);
                } else {
                    tempLine.setOperand(line[1]);
                    tempLine.setError("***** Invalid operand");
                }
                if (tempLine.getOpCode() == "END"){
                    if (configuredLines.size() != 0 && configuredLines[0].getOpCode() == "START"){
                        if (configuredLines[0].getLabel() != tempLine.getOperand()){
                            tempLine.setError("***** Invalid operand");
                        }
                    }
                }
            }
        } else if (line.size()  == 3) {
            if (operations.checkOperation(line[0])){
                tempLine.setError("***** Invalid Label");
            }
            tempLine.setLabel(line[0]);
            if (!operations.checkOperation(line[1])) {
                tempLine.setOpCode(line[1]);
                tempLine.setError("***** unrecognized operation code");
                tempLine.setOperand(line[2]);

            } else {
                tempLine.setOpCode(line[1]);
                OpGroups *opGroups = operations.checkOperation(line[1]);
                if ((*opGroups).checkOperand(line[2], line[1])) {
                    tempLine.setOperand(line[2]);
                } else {
                    tempLine.setOperand(line[2]);
                    tempLine.setError("***** Invalid operand");
                }
            }
        }
        configuredLines.push_back(tempLine);
}

void LinesConfiguration::checkEQU(vector<string> line)
{

}

