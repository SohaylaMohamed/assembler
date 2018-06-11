#include <iostream>
#include<fstream>
#include <vector>
#include "readFile.h"
#include "LinesConfiguration.h"
#include "Address.h"
#include "writeFile.h"
#include "SymTable.h"
#include "Expressions.h"
#include "object_code.h"

using namespace std;


int main() {

    readFile fileLoader("test.txt");
    fileLoader.read();
    vector<vector <string>> lines= fileLoader.getLines();
    LinesConfiguration linesConfiguration ;
    SymTable symTable ;
    vector<Line> outlines = linesConfiguration.configureLines(lines);
    Address address;
    outlines =  address.setAddresses(outlines);
    outlines = symTable.createSymTable(outlines);
    Expressions expressions;
    expressions.evaluateExpressions(outlines , symTable.symTable);
    writeFile write ;
    write.write(outlines,symTable.symTable);
    object_code ob = object_code(symTable);
    return 0;
}