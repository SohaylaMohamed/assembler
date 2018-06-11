//
// Created by karim on 6/11/2018.
//

#ifndef ASSEMBLERPASS1_NEWEXPRESSIONS_H
#define ASSEMBLERPASS1_NEWEXPRESSIONS_H

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "Line.h"
#include "Term.h"

class newExpressions {

public:
    bool isExpression(std::basic_string<char> operand);
    string makeExpression(string operand, map<string, string> symTable, bool *pBoolean);
    string infixToPostfix(string expression);
    Term evaluateExpressions(vector<Line> &configuredLines, map<string, string> &symTable, map<string, bool> &isAbsolute);
    bool contains_number(const string &c);
    string calculate(Term term_1, Term term_2, char c, map<string, string> &symTable);
    Term evaluatePostFix(string s, map<string, string> &symTab, map<string, bool> &isAbsolute);
};


#endif //ASSEMBLERPASS1_NEWEXPRESSIONS_H
