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
public:
    void evaluateExpressions(vector<Line> &configuredLines, map <string, string>& symTable);

    bool isExpression(string oprand);


    char peek();

    char get();

    int number();

    int factor();

    int term();

    int calculate();

    string makeExpression(string operand, map<string, string> symTable, bool *pBoolean);
};


#endif //ASSEMBLERPASS1_EXPRESSIONS_H
