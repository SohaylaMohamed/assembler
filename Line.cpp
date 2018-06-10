//
// Created by LENOVO on 21/04/2018.
//
#include <iostream>

using namespace std;

#include "Line.h"

int Line::getLineNo() const {
    return lineNo;
}

void Line::setLineNo(int lineNo) {
    Line::lineNo = lineNo;
}

const string &Line::getAddress() const {
    return address;
}

void Line::setAddress(const string &address) {
    Line::address = address;
}

const string &Line::getLabel() const {
    return label;
}

void Line::setLabel(const string &label) {
    Line::label = label;
}

const string &Line::getOpCode() const {
    return opCode;
}

void Line::setOpCode(const string &opCode) {
    Line::opCode = opCode;
}

const string &Line::getOperand() const {
    return operand;
}

void Line::setOperand(const string &operand) {
    Line::operand = operand;
}

const string &Line::getComment() const {
    return comment;
}

void Line::setComment(const string &comment) {
    Line::comment = comment;
}

const string &Line::getError() const {
    return error;
}

void Line::setError(const string &error) {
    Line::error = Line::error + error;
}

int Line::getFormatNo() const {
    return formatNo;
}

void Line::setFormatNo(int formatNo) {
    Line::formatNo = formatNo;
}

bool Line::isAbsolute() const {
    return absolute;
}

void Line::setAbsolute(bool absolute) {
    Line::absolute = absolute;
}
