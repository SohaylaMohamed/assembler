//
// Created by Karim on 6/7/2018.
//

#include <iostream>
using namespace std;
#include "Literal.h"

const string &Literal::getName() const {
    return name;
}

void Literal::setName(const string &name) {
    Literal::name = name;
}

const string &Literal::getHexValue() const {
    return hexValue;
}

void Literal::setHexValue(const string &hexValue) {
    Literal::hexValue = hexValue;
}

bool Literal::isPrinted() const {
    return printed;
}

void Literal::setPrinted(bool isPrinted) {
    Literal::printed = isPrinted;
}

const string &Literal::getAddress() const {
    return address;
}

void Literal::setAddress(const string &address) {
    Literal::address = address;
}
