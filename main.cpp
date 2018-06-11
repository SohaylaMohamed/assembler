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
    cout << "done3";
    pass2 pass = pass2();
    cout << "done5";

    outlines = symTable.createSymTable(outlines);

    Expressions expressions;
    vector<string> output = pass.generateObjectCode(outlines, linesConfiguration.litTab);

    expressions.evaluateExpressions(outlines , symTable.symTable);

    cout << "done4";


    cout << "done6";

    cout << "done";
    writeFile write ;
    write.write(outlines,symTable.symTable);
    return 0;
}