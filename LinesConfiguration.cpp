//
// Created by LENOVO on 21/04/2018.
//
#include <iostream>
#include "Line.h"
using namespace std;
#include "LinesConfiguration.h"
void LinesConfiguration::configureLines(vector<vector> lines) {
    for (int i = 0; i <lines.size() ; ++i) {

    }
}
void LinesConfiguration::checkLine(vector<string> line) {
    Line tempLine;
    if (line[line.size()-1].find_first_of('*')!= -1){
        tempLine.setComment(line[line.size()-1]);
        if (line.size()-1 == 1){
            tempLine.setOpCode(line[0]);
        }
        else if (line.size()-1 == 2){

        }
    }
}