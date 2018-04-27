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
    //Todo length of label/operation/operand
    //TODO handle the error of having repeated label/operation/operand in the same line
    Line tempLine;
    Operations operations;
    operations.readOperations();

    if (line[line.size() - 1].find_first_of('*') != -1) {
        if (line[line.size() - 1].size()<=30)
            tempLine.setComment(line[line.size() - 1]);
        else
            tempLine.setComment("INVALID");
    }else {
        tempLine.setComment("");
    }
        if (line.size() - 1 == 1) {
            if (line[0].find_first_of('.') != -1) {
                if (line[0].size()<=30)
                    tempLine.setComment(line[0]);
                else
                    tempLine.setComment("INVALID");
            } else {
                if (line[0].size()<=5)
                    tempLine.setOpCode(line[0]);
                else
                    tempLine.setOpCode("INVALID");
            }
        } else if (line.size() - 1 == 2) {
            if (!operations.checkOperation(line[0])) {
                if (line[0].size()<=8)
                    tempLine.setLabel(line[0]);
                else
                    tempLine.setLabel("INVALID");
                if (!operations.checkOperation(line[1]))
                    tempLine.setOpCode("INVALID");
                else
                {
                    if (line[1].size()<=5)
                        tempLine.setOpCode(line[1]);
                    else
                        tempLine.setOpCode("INVALID");
                }
            } else {
                if (line[0].size()<=5)
                    tempLine.setOpCode(line[0]);
                else
                    tempLine.setOpCode("INVALID");

                OpGroups *opGroups = operations.checkOperation(line[0]);
                if ((*opGroups).checkOperand(line[1])) {
                    if (line[1].size()<=18)
                        tempLine.setOperand(line[1]);
                    else
                        tempLine.setOperand("INVALID");
                } else
                    tempLine.setOperand("INVALID");
            }
        } else if (line.size() - 1 == 3) {
            if (line[0].size()<=8)
                tempLine.setLabel(line[0]);
            else
                tempLine.setLabel("INVALID");
            if (!operations.checkOperation(line[1])) {
                tempLine.setOpCode("INVALID");
                if (line[2].size()<=18)
                    tempLine.setOperand(line[2]);
                else
                    tempLine.setOperand("INVALID");
            } else {
                if (line[1].size()<=5)
                    tempLine.setOpCode(line[1]);
                else
                    tempLine.setOpCode("INVALID");
                OpGroups *opGroups = operations.checkOperation(line[1]);
                if ((*opGroups).checkOperand(line[2])) {
                    if (line[2].size()<=18)
                        tempLine.setOperand(line[2]);
                    else
                        tempLine.setOperand("INVALID");
                } else
                    tempLine.setOperand("INVALID");
            }
        }
        configuredLines.push_back(tempLine);
}

