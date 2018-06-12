//
// Created by HP on 6/10/2018.
//

#ifndef ASSEMBLERPASS1_PASS2_H
#define ASSEMBLERPASS1_PASS2_H


#include <vector>
#include <map>
#include "Line.h"
#include "Literal.h"

class pass2 {
public:
    void printObjectProgam(vector<string> objectCode, vector<Line> lines);

    int toInt(string number);

    int calculateNumOfOperands(const string &basic_string);


    vector<string> generateObjectCode(vector<Line> lines, std::map<string, Literal> litab);
};


#endif //ASSEMBLERPASS1_PASS2_H
