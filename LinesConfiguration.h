//
// Created by LENOVO on 21/04/2018.
//

#ifndef ASSEMBLERPASS1_LINESCONFIGURATION_H
#define ASSEMBLERPASS1_LINESCONFIGURATION_H

#include <iostream>
#include "Line.h"
#include <vector>
#include "Operations.h"
#include "Literal.h"

using namespace std;

class LinesConfiguration {
private:
    Operations operations;
    vector<Line> configuredLines;
    map<string , Literal> litTab;
public:
    vector<Line> configureLines(vector<vector<string>> lines);
    void checkLine(vector<string> line);
};


#endif //ASSEMBLERPASS1_LINESCONFIGURATION_H
