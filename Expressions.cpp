//
// Created by Karim on 6/7/2018.
//

#include <vector>
#include <map>
#include<stack>
#include <sstream>
#include "Expressions.h"
#include "Line.h"

void Expressions::evaluateExpressions(vector<Line> &configuredLines, map<string, string> &symTable) {
    for (int i = 0; i < configuredLines.size(); ++i) {
        string opearnd = configuredLines[i].getOperand();
        if (opearnd=="*")
        {
            configuredLines[i].setOperand(configuredLines[i].getAddress());
        }
        else if (isExpression(opearnd)) {
            bool noUndefinedLabels = true;
            string configuredExpression = makeExpression(opearnd, symTable, &noUndefinedLabels);
            if (!noUndefinedLabels){
                configuredLines[i].setError("**** Undefined Label");
            }
            else {
                expressionToParse = configuredExpression.c_str();
                int result = calculate();
                stringstream ss;
                ss << result;
                cout << configuredExpression << "=" << result << "\n";
                configuredLines[i].setOperand(ss.str());
            }
        }
    }
}


bool Expressions::isExpression(string operand) {
    if (operand.find_first_of('(') != -1 || operand.find_first_of('*') != -1 || operand.find_first_of('/') != -1 ||
        operand.find_first_of('-') != -1 || operand.find_first_of('+') != -1) {
        return true;
    }
    return false;
}

string Expressions::makeExpression(string operand, map<string, string> symTable, bool *pBoolean) {
    int startingAddress = 0;
    for (int i = 0; i <operand.size(); ++i) {
        if (operand[i]>='A' && operand[i]<='Z'){
            startingAddress = i;
            string temp = "";
            while((operand[i]>='A' && operand[i]<='Z') || (operand[i]>= '0' && operand[i]<='9')){
                temp = temp + operand[i];
                i++;
            }
            cout<<"--------------"<<temp<<"\n";
            if (symTable.find(temp) != symTable.end()){
                string index = symTable[temp];
                operand.replace(startingAddress, temp.length(), index);
                i += index.size() - temp.size();
            }
            else{
                *pBoolean = false;
            }
            //i--;
        }
    }
    return operand;
}

char Expressions::peek()
{
    return *expressionToParse;
}

char Expressions::get()
{
    return *expressionToParse++;
}

int Expressions:: number()
{
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
    }
    return result;
}

int Expressions::factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        int result = calculate();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

int Expressions::term()
{
    int result = factor();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor();
    return result;
}

int Expressions::calculate()
{
    int result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}


