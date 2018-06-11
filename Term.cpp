//
// Created by karim on 6/11/2018.
//

#include "Term.h"

bool Term::isIsLabel() const {
    return isLabel;
}

void Term::setIsLabel(bool isLabel) {
    Term::isLabel = isLabel;
}

const string &Term::getLabelName() const {
    return labelName;
}

void Term::setLabelName(const string &labelName) {
    Term::labelName = labelName;
}

const string &Term::getValue() const {
    return value;
}

void Term::setValue(const string &value) {
    Term::value = value;
}

bool Term::isIsAbsolute() const {
    return isAbsolute;
}

void Term::setIsAbsolute(bool isAbsolute) {
    Term::isAbsolute = isAbsolute;
}

const string &Term::getError() const {
    return error;
}

void Term::setError(const string &error) {
    Term::error = error;
}
