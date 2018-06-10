//
// Created by HP on 6/10/2018.
//

#ifndef ASSEMBLERPASS1_PASS2_H
#define ASSEMBLERPASS1_PASS2_H


#include <vector>
#include "Line.h"

class pass2 {
    vector<string> generateObjectCode(vector<Line> lines);

    void printObjectProgam(vector<string> objectCode, vector<Line> lines);

};


#endif //ASSEMBLERPASS1_PASS2_H
