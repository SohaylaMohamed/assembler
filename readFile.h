//
// Created by HANAN SAMIR on 21/04/2018.
//

#ifndef ASSEMBLER_READFILE_H
#define ASSEMBLER_READFILE_H
#include<fstream>
#include <regex>
#include<vector>
using namespace std;
class readFile {
public:
    readFile(string fileName);
    void read();
    vector<vector <string>> getLines();


private:
    ifstream inFile;
    std::vector<std::string> lineVector;

    vector<vector<string> > allLines;
    string fileName = "";
    string line = "";
    bool comment();
    bool Blank();
    bool Stringwithoutequal();
    bool Stringwithequal();


};
#endif //ASSEMBLER_READFILE_H
