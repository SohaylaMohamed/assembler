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
    for (int i = 0; i < lines.size(); ++i) {
        checkLine(lines[i]);
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
    Operations operations;

    if (line[line.size() - 1].find_first_of('*') != -1) {
        tempLine.setComment(line[line.size() - 1]);
    }else {
        tempLine.setComment("");
    }
    if (line.size() - 1 == 1) {
        if (line[0].find_first_of('.') != -1) {
            tempLine.setComment(line[0]);
        } else {
            tempLine.setOpCode(line[0]);
        }
    } else if (line.size() - 1 == 2) {
        if (!operations.checkOperation(line[0])) {
            tempLine.setLabel(line[0]);
            if (!operations.checkOperation(line[1]))
                tempLine.setOpCode("INVALID");
            else
                tempLine.setOpCode(line[1]);
        } else {
            tempLine.setOpCode(line[0]);
            OpGroups *opGroups = operations.checkOperation(line[0]);
            if ((*opGroups).checkOperand(line[1])) {
                tempLine.setOperand(line[1]);
            } else
                tempLine.setOperand("INVALID");
        }
    } else if (line.size() - 1 == 3) {
        tempLine.setLabel(line[0]);
        if (!operations.checkOperation(line[1])) {
            tempLine.setOpCode("INVALID");
            tempLine.setOperand(line[2]);

        } else {
            tempLine.setOpCode(line[1]);
            OpGroups *opGroups = operations.checkOperation(line[1]);
            if ((*opGroups).checkOperand(line[2])) {
                tempLine.setOperand(line[2]);
            } else
                tempLine.setOperand("INVALID");
        }
    }
    configuredLines.push_back(tempLine);


}

