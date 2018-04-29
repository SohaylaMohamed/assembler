//
// Created by LENOVO on 21/04/2018.
//
#include <iostream>

using namespace std;
#ifndef ASSEMBLERPASS1_LINE_H
#define ASSEMBLERPASS1_LINE_H


class Line {
public:
    int getLineNo() const;

    void setLineNo(int lineNo);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getLabel() const;

    void setLabel(const string &label);

    const string &getOpCode() const;

    void setOpCode(const string &opCode);

    const string &getOperand() const;

    void setOperand(const string &operand);

    const string &getComment() const;

    void setComment(const string &comment);

private:
    int lineNo;
    string address;
    string label;
    string opCode;
    string operand;
    string comment;
    string error;
public:
    const string &getError() const;

    void setError(const string &error);
};

#endif //ASSEMBLERPASS1_LINE_H