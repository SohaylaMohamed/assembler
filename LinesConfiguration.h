//
// Created by LENOVO on 21/04/2018.
//

#ifndef ASSEMBLERPASS1_LINESCONFIGURATION_H
#define ASSEMBLERPASS1_LINESCONFIGURATION_H

#include <iostream>
#include "Line.h"
#include <vector>
#include "Operations.h"
using namespace std;

class LinesConfiguration {
private:
    Operations operations;
public:


    vector<Line> configureLines(vector<vector<string>> lines);
    void checkEQU(vector<string> line);

    void checkLine(vector<string> line);

    bool checkOp(string string1);

private:
    vector<Line> configuredLines;
};


#endif //ASSEMBLERPASS1_LINESCONFIGURATION_H
