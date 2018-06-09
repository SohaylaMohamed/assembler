#include <iostream>
#include<fstream>
#include <vector>
#include "readFile.h"
#include "LinesConfiguration.h"
#include "Operations.h"
#include "Address.h"
#include "writeFile.h"
#include "SymTable.h"

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
    writeFile write ;
    write.write(outlines,symTable.symTable);

//    for (int k = 0; k < outlines.size(); ++k) {
//        cout<<outlines[k].getAddress()<<" ";
//        cout<<outlines[k].getLabel()<<" ";
//        cout<<outlines[k].getOpCode()<<" ";
//        cout<<outlines[k].getOperand()<<" ";
//        cout<<outlines[k].getComment()<<" \n";
//        if (!outlines[k].getError().empty()){
//            cout << outlines[k].getError()<<"\n";
//        }
//
//    }
    return 0;
}