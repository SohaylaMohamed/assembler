#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <map>
#include "writeFile.h"
#include "LinesConfiguration.h"

using namespace std;

void writeFile::write(vector<Line> outlines , map <string, string> symTable){
     outFile.open("output.txt");
     if(outFile.is_open()) {
        outFile << "Line no." << "        ";
        outFile << "Address" << "         ";
        outFile << "Label" << "        ";
        outFile << "Mnemonic op_code" << "         ";
        outFile << "Operands" << "                ";
        outFile << "comments" << "";
        outFile << " \n";
        outFile << addDashes(112);
        outFile << " \n";
        string spaces;
        for (int i = 0; i < outlines.size(); ++i) {
           outFile << i << "";
           stringstream ss;
           ss << i;
           spaces = addSpaces(ss.str(), 16);
           outFile << spaces;
           outFile << outlines[i].getAddress() << "";
           spaces = addSpaces(outlines[i].getAddress(), 16);
           outFile << spaces;
           outFile << outlines[i].getLabel() << "";
           spaces = addSpaces(outlines[i].getLabel(), 13);
           outFile << spaces;
           outFile << outlines[i].getOpCode() << "";
           spaces = addSpaces(outlines[i].getOpCode(), 25);
           outFile << spaces;
           outFile << outlines[i].getOperand() << "";
           spaces = addSpaces(outlines[i].getOperand(), 24);
           outFile << spaces;
           outFile << outlines[i].getComment() << "\n";
           if (!outlines[i].getError().empty()) {
              spaces = addSpaces(outlines[i].getOpCode(), 25);
              outFile << spaces;
              outFile << outlines[i].getError() <<"\n";
           }
        }

        outFile << " \n\n";
        outFile << addDashes(112);
        outFile << " \n";
        outFile << spaces;
        outFile<<"\t\t\t\t\t\t\t\t\t\tSymbol Table \n\n";
        outFile <<"\t\t\t\t\t\t\t\t\t\t\t\t"<< "Label" << "\t\t\t\t"
                <<"|\t\t\t\t"
                <<   "Address" << "\n";
        outFile<<"\t\t\t\t\t\t\t\t\t" << addDashes(60)<<"\n";
        map <string, string> :: iterator itr;
        for (itr = symTable.begin(); itr != symTable.end(); ++itr)
        {
           outFile <<"\t\t\t\t\t\t\t\t\t\t\t\t"<< itr->first << "\t\t\t\t"
                    <<"|\t\t\t\t"
                    <<   itr->second << "\n";
        }

    }

}
string writeFile::addSpaces (string str,int addIfEmpty)
{
   string spaces ="";
   for (int i=0;i<addIfEmpty-str.length();i++)
      spaces += " ";
   return spaces;
}

string writeFile::addDashes (int num)
{
   string dashes ="";
   for (int i=0;i<num;i++)
      dashes += "-";
   return dashes;
}
