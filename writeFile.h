#ifndef WRITEFILE_H_INCLUDED
#define WRITEFILE_H_INCLUDED
#include<fstream>
#include <vector>
#include "LinesConfiguration.h"
using namespace std;
class writeFile {
public:
    void write(vector<string> addresses,vector<Line> outlines);

private:
    ofstream outFile;
    string addSpaces (string str,int addIfEmpty);
    string addDashes (int num);

};


#endif // WRITEFILE_H_INCLUDED
