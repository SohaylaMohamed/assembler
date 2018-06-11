//
// Created by Karim on 6/7/2018.
//

#ifndef ASSEMBLERPASS1_EXPRESSIONS_H
#define ASSEMBLERPASS1_EXPRESSIONS_H


#include <vector>
#include <map>
#include "Line.h"

class Expressions {

private:
    const char * expressionToParse;
    bool absolute;
    map<string,bool> termState ;
public:
    bool evaluateExpressions(vector<Line> &configuredLines, map <string, string>& symTable);

    bool isExpression(string oprand);


    char peek();

    char get();

    int number();

    int factor();

    int term();

    int calculate();

    string makeExpression(string operand, map<string, string> symTable, bool *pBoolean);

    string NumberToString(int Number);

    string expressionType(string basic_string, map<string, string> &map);
};


#endif //ASSEMBLERPASS1_EXPRESSIONS_H
