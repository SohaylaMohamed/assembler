#include <iostream>
#include<fstream>
#include <vector>
#include "readFile.h"
#include "LinesConfiguration.h"
#include "Address.h"
#include "writeFile.h"
#include "SymTable.h"
#include "Expressions.h"
#include "pass2.h"
#include "newExpressions.h"

using namespace std;


int main() {
    readFile fileLoader("test.txt");
    fileLoader.read();
    vector<vector <string>> lines= fileLoader.getLines();
    LinesConfiguration linesConfiguration ;
    SymTable symTable ;
    cout << "done1";

    vector<Line> outlines = linesConfiguration.configureLines(lines);
    Address address;
    cout << "done2";

    outlines =  address.setAddresses(outlines,linesConfiguration.litTab);
    pass2 pass = pass2();

    outlines = symTable.createSymTable(outlines);
    cout << "done3";

    newExpressions expressions;
    expressions.evaluateExpressions(outlines , symTable.symTable,symTable.symTableType);
    writeFile write;
    write.write(outlines, symTable.symTable);
    cout << "done5";

    vector<string> output = pass.generateObjectCode(outlines, linesConfiguration.litTab);
    pass.printObjectProgam(output, outlines);


    return 0;
}