//
// Created by LENOVO on 21/04/2018.
//

#ifndef ASSEMBLERPASS1_LINESCONFIGURATION_H
#define ASSEMBLERPASS1_LINESCONFIGURATION_H
#include <iostream>
#include "Line.h"
#include <vector>

using namespace std;

class LinesConfiguration {
public:
    vector<Line> lines;
    void configureLines (vector<vector> lines);
    void checkLine (vector<string> line);

};


#endif //ASSEMBLERPASS1_LINESCONFIGURATION_H
