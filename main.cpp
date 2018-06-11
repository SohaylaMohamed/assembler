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
#include "newExpressions.h"

using namespace std;


int main() {
    vector<vector <string>> lines;
    LinesConfiguration linesConfiguration ;
    SymTable symTable ;
    vector<Line> outlines;
    Address address;
    newExpressions expressions;
    writeFile write ;

    readFile fileLoader("test.txt");
    fileLoader.read();
    lines= fileLoader.getLines();
    outlines = linesConfiguration.configureLines(lines);
    outlines =  address.setAddresses(outlines,linesConfiguration.litTab);
    outlines = symTable.createSymTable(outlines);
    expressions.evaluateExpressions(outlines , symTable.symTable,symTable.symTableType);
    write.write(outlines,symTable.symTable);
    object_code ob = object_code(symTable);
    return 0;
}