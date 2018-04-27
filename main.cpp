#include <iostream>
#include<fstream>
#include <vector>
#include "readFile.h"
#include "LinesConfiguration.h"
#include "Operations.h"
#include "Address.h"

using namespace std;


int main() {

    readFile fileLoader("C:\\Users\\karim\\CLionProjects\\assembler\\test.txt");
    fileLoader.read();
    vector<vector <string>> lines= fileLoader.getLines();
    for(int i=0;i<lines.size();i++){
        for(int j=0;j<lines.at(i).size();j++){
            cout <<  lines.at(i).at(j)<<" ";
        }
        cout<<" "<<endl;
    }
    LinesConfiguration linesConfiguration ;
    vector<Line> outlines = linesConfiguration.configureLines(lines);
    Address address;
    vector<string> addresses =  address.setAddresses(outlines);
    for (int k = 0; k < outlines.size(); ++k) {
        cout<<addresses[k]<<" ";
        cout<<outlines[k].getLabel()<<" ";
        cout<<outlines[k].getOpCode()<<" ";
        cout<<outlines[k].getOperand()<<" ";
        cout<<outlines[k].getComment()<<" \n";




    }
    return 0;
}