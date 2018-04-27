//
// Created by karim on 4/25/2018.
//

#ifndef ASSEMBLERPASS1_ADDRESS_H
#define ASSEMBLERPASS1_ADDRESS_H

#include <iostream>
#include <vector>
#include "Operations.h"
#include "Line.h"
#include <string.h>

using namespace std;

class Address {
public:
    vector<string> setAddresses(vector<Line> configuredLines);

private:
    vector<string> addresses;
};


#endif //ASSEMBLERPASS1_ADDRESS_H
