#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include "writeFile.h"
#include "LinesConfiguration.h"

using namespace std;

void writeFile::write(vector<string> addresses,vector<Line> outlines){
     outFile.open("output.txt");
     if(outFile.is_open()){
        outFile << "Line no."<<"        ";
        outFile << "Address"<<"         ";
        outFile << "Label"<<"        ";
        outFile << "Mnemonic op_code"<<"         ";
        outFile << "Operands"<<"                ";
        outFile << "comments"<<"";
        outFile<<" \n";
        outFile<< addDashes(112);
        outFile<<" \n";
        string spaces;
        for (int i = 0; i < outlines.size(); ++i) {
        outFile<<i<<"";
        stringstream ss;
        ss << i;
        spaces=addSpaces(ss.str(),16);
        outFile<<spaces;
        outFile<<addresses[i]<<"";
        spaces=addSpaces(addresses[i],16);
        outFile<<spaces;
        outFile<<outlines[i].getLabel()<<"";
        spaces=addSpaces(outlines[i].getLabel(),13);
        outFile<<spaces;
        outFile<<outlines[i].getOpCode()<<"";
        spaces=addSpaces(outlines[i].getOpCode(),25);
        outFile<<spaces;
        outFile<<outlines[i].getOperand()<<"";
        spaces=addSpaces(outlines[i].getOperand(),24);
        outFile<<spaces;
        outFile<<outlines[i].getComment()<<"\n";
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
