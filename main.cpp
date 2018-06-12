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
    pass2 pass = pass2();

    outlines = symTable.createSymTable(outlines);
    cout << "done3";

    writeFile write;
    write.write(outlines, symTable.symTable);
    Expressions expressions;
    cout << "done5";

    vector<string> output = pass.generateObjectCode(outlines, linesConfiguration.litTab);
    pass.printObjectProgam(output, outlines);
    expressions.evaluateExpressions(outlines , symTable.symTable);


    return 0;
}