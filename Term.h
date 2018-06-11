//
// Created by karim on 6/11/2018.
//

#ifndef ASSEMBLERPASS1_TERM_H
#define ASSEMBLERPASS1_TERM_H
#include <iostream>
using namespace std;


class Term {

private:
    bool isLabel;
    string labelName;
    string value;
    bool isAbsolute=false;
    string error;
public:
    const string &getError() const;

    void setError(const string &error);

public:
    bool isIsLabel() const;

    void setIsLabel(bool isLabel);

    const string &getLabelName() const;

    void setLabelName(const string &labelName);

    const string &getValue() const;

    void setValue(const string &value);

    bool isIsAbsolute() const;

    void setIsAbsolute(bool isAbsolute);


};


#endif //ASSEMBLERPASS1_TERM_H
