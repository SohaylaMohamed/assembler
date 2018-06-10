//
// Created by Karim on 6/7/2018.
//

#include <iostream>
#include <vector>

using namespace std;

#ifndef ASSEMBLERPASS1_LITERAL_H
#define ASSEMBLERPASS1_LITERAL_H


class Literal {
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getHexValue() const;

    void setHexValue(const string &hexValue);

    bool isPrinted() const;

    void setPrinted(bool printed);


private :
    string name;
    string hexValue;
    bool printed;
};


#endif //ASSEMBLERPASS1_LITERALS_H
