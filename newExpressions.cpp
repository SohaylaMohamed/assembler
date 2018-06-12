//
// Created by karim on 6/11/2018.
//

#include <vector>
#include <map>
#include <sstream>
#include <stack>
#include "newExpressions.h"
#include "Line.h"
#include "Term.h"


void newExpressions::evaluateExpressions(vector<Line> &configuredLines, map<string, string> &symTable,
                                         map<string, bool> &isAbsolute) {

    Term result;
    for (int i = 0; i < configuredLines.size(); ++i) {
        string expression = configuredLines[i].getOperand();
        if (expression == "*") // asterisk -> current locCTR
        {
            configuredLines[i].setOperand(configuredLines[i].getAddress());
        } else if (isExpression(expression)) {
            string postFix = infixToPostfix(expression);
            result =evaluatePostFix(postFix,symTable,isAbsolute);

            //replace the expression by its value
            if (result.getError()!="invalid")
            {
                string resultValue = result.getValue();
                std::ostringstream ss;
                ss << std::hex << resultValue;
                cout << expression << "=" << ss.str() << "\n";
                if (ss.str().size()>4)
                    configuredLines[i].setOperand(ss.str().substr(ss.str().size()-1-3));
                else
                    configuredLines[i].setOperand(ss.str());
                if (configuredLines[i].getOpCode()=="EQU")
                {
                    symTable[configuredLines[i].getLabel()]=configuredLines[i].getOperand();
                    isAbsolute[configuredLines[i].getLabel()]=result.isIsAbsolute();
                    configuredLines[i].setAbsolute(result.isIsAbsolute());
                }
            }
            else
            {
                configuredLines[i].setOperand(result.getError());
            }

        }
    }
}

bool newExpressions::isExpression(string operand) {
    if (operand.find_first_of('(') != -1 || operand.find_first_of('*') != -1 || operand.find_first_of('/') != -1 ||
        operand.find_first_of('-') != -1 || operand.find_first_of('+') != -1) {
        return true;
    }
    return false;
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression
//to postfix expression
string newExpressions::infixToPostfix(string s) {
    std::stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for (int i = 0; i < l; i++) {
        // If the scanned character is an operand, add it to output string.
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')) {

            while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')) {
                ns += s[i];
                i++;
            }
            i--;
            ns += " ";
        }
            // If the scanned character is an ‘(‘, push it to the stack.
        else if (s[i] == '(')
            st.push('(');
            // If the scanned character is an ‘)’, pop and to output string from the stack
            // until an ‘(‘ is encountered.
        else if (s[i] == ')') {
            while (st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ns += c;
                ns += " ";
            }
            if (st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        }

            //If an operator is scanned
        else {
            while (st.top() != 'N' && prec(s[i]) <= prec(st.top())) {
                char c = st.top();
                st.pop();
                ns += c;
                ns += " ";
            }
            st.push(s[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while (st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;
        ns += " ";
    }
    return ns;
}

Term newExpressions::evaluatePostFix(string s, map<string, string> &symTable, map<string, bool> &isAbsolute) {
    stack <Term> postStack;

    for (int i = 0; i < s.length(); i++) {

        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')) {
            string termStr;
            while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')) {
                termStr += s[i];
                i++;
            }
            i--;
            Term t;
            if ((termStr[0] >= 'A' && termStr[0] <= 'Z')) {
                t.setIsLabel(true);
                t.setLabelName(termStr);
                t.setIsAbsolute(isAbsolute[termStr]);

            } else {
                t.setIsLabel(false);
                t.setValue(termStr);
                t.setIsAbsolute(true);
            }
            postStack.push(t);
        } else if (s[i] == '+') {
            Term term_1 = postStack.top();
            postStack.pop();
            Term term_2 = postStack.top();
            postStack.pop();

            if (!term_1.isIsAbsolute() && !term_2.isIsAbsolute()) {
                //relative + relative  = error
                Term result ;
                result.setError("invalid");
                return result;

            } else if (term_1.isIsAbsolute() && term_2.isIsAbsolute()) {
                //absolute + absolute = absolute
                Term result;
                result.setIsAbsolute(true);
                result.setIsLabel(false);
                result.setValue(calculate(term_1, term_2, '+', symTable));
                postStack.push(result);
            } else if ((term_1.isIsAbsolute() && !term_2.isIsAbsolute()) ||
                       (!term_1.isIsAbsolute() && term_2.isIsAbsolute())) {
                //absolute+relative = relative
                Term result;
                result.setIsAbsolute(false);
                result.setIsLabel(false);
                result.setValue(calculate(term_1, term_2, '+', symTable));
                postStack.push(result);
            }
        } else if (s[i] == '-') {
            Term term_1 = postStack.top();
            postStack.pop();
            Term term_2 = postStack.top();
            postStack.pop();

            if (term_1.isIsAbsolute() && !term_2.isIsAbsolute()) {
                //absolute - relative  = error
                Term result ;
                result.setError("invalid");
                return result;
            } else if ((!term_1.isIsAbsolute() && !term_2.isIsAbsolute()) ||
                       (term_1.isIsAbsolute() && term_2.isIsAbsolute())) {
                //relative - relative  = absolute  , absolute - absolute = absolute
                Term result;
                result.setIsAbsolute(true);
                result.setIsLabel(false);
                result.setValue(calculate(term_1, term_2, '-', symTable));
                postStack.push(result);
            } else if (!term_1.isIsAbsolute() && term_2.isIsAbsolute()) {
                //relative-absolute = relative
                Term result;
                result.setIsAbsolute(false);
                result.setIsLabel(false);
                result.setValue(calculate(term_1, term_2, '-', symTable));
                postStack.push(result);
            }
        }
    }
    return postStack.top();
}

bool newExpressions::contains_number(const std::string &c) {
    if (c.find('0') != std::string::npos ||
        c.find('1') != std::string::npos ||
        c.find('2') != std::string::npos ||
        c.find('3') != std::string::npos ||
        c.find('4') != std::string::npos ||
        c.find('5') != std::string::npos ||
        c.find('6') != std::string::npos ||
        c.find('7') != std::string::npos ||
        c.find('8') != std::string::npos ||
        c.find('9') != std::string::npos) {
        return true;
    }

    return false;
}

string newExpressions::calculate(Term term_1, Term term_2, char c, map<string, string> &symTable) {
    int value1;
    int value2;
    int result;

    if (!term_1.isIsLabel()) {
        std::istringstream(term_1.getValue()) >> value1;
    } else {
        std::istringstream(symTable[term_1.getLabelName()]) >> std::hex >> value1;
    }
    if (!term_2.isIsLabel()) {
        std::istringstream(term_2.getValue()) >> value2;
    } else {
        std::istringstream(symTable[term_2.getLabelName()]) >> std::hex >> value2;
    }

    switch (c) {
        case '+':
            result = value2 + value1;
            break;
        case '-':
            result = value2 - value1;
            break;
        case '*':
            result = value2 * value1;
            break;
        case '/':
            result = value2 / value1;
            break;
    }

    std::ostringstream ss;
    ss << result;
    return ss.str();
}

