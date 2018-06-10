//
// Created by LENOVO on 21/04/2018.
//
#include <iostream>
#include "Line.h"
#include "Operations.h"
#include <ctype.h>

using namespace std;
#include "LinesConfiguration.h"

vector<Line> LinesConfiguration::configureLines(vector<vector<string>> lines) {
    cout<<"Reached configureLines";
    operations.readOperations();

    for (int i = 0; i < lines.size(); ++i) {
        checkLine(lines[i]);
        cout<<"Line " << configuredLines[i].getOpCode()<<"is of format"<<configuredLines[i].getFormatNo()<<endl;
    }

    cout<<"first loop succeeded";
    for (int j = 0; j < configuredLines.size(); ++j) {
        for (int k = j + 1; k < configuredLines.size(); ++k) {
            if (configuredLines[j].getLabel() == configuredLines[k].getLabel() &&
                (configuredLines[j].getLabel() != "") && (configuredLines[j].getLabel() != "*")) {
                configuredLines[k].setError("****Error:Sympol\'" + configuredLines[k].getLabel() + "\'already defined");
            }
        }
    }
    cout<"configureLines succeeded";
    return configuredLines;
}

void LinesConfiguration::checkLine(vector<string> line) {
    for (int i = 0; i < line.size(); ++i) {
        for (int j = 0; j < line[i].size(); ++j) {
            (line[i])[j] = toupper((line[i])[j]);
        }
    }
    Line tempLine;

    /* asterisk Commets*/
//    if (line[line.size() - 1].find_first_of('*') != -1) {
//        tempLine.setComment(line[line.size() - 1]);
//        line.pop_back();
//    } else {
//        tempLine.setComment("");
//    }
    if (line.size() == 1) {
        if (line[0].find_first_of('.') != -1) {
            tempLine.setComment(line[0]);
        } else {
            tempLine.setOpCode(line[0]);
            tempLine.setFormatNo(1);
        }
    } else if (line.size() == 2) {
        if (!operations.checkOperation(line[0])) {
            tempLine.setLabel(line[0]);
            if (!operations.checkOperation(line[1])) {
                tempLine.setOpCode(line[1]);
                tempLine.setError("***** unrecognized operation code");
            } else {
                tempLine.setOpCode(line[1]);
                tempLine.setFormatNo(1);
            }
        } else {
            tempLine.setOpCode(line[0]);
            if (line[0].find_first_of('+') != -1)
                line[0] = line[0].substr(1, line[0].size() - 1);
            OpGroups *opGroups = operations.checkOperation(line[0]);
            if ((*opGroups).checkOperand(line[1], line[0])) {
                tempLine.setOperand(line[1]);
                if((*opGroups).getSize()==2)
                {
                    tempLine.setFormatNo(2);
                } else
                {
                    if ( (tempLine.getOpCode())[0] =='+' )
                    {
                        tempLine.setFormatNo(4);
                    }
                    else
                    {
                        tempLine.setFormatNo(3);
                    }

                }
            } else {
                tempLine.setOperand(line[1]);
                tempLine.setError("***** Invalid operand");
            }
            if (tempLine.getOpCode() == "END") {
                if (configuredLines.size() != 0 && configuredLines[0].getOpCode() == "START") {
                    if (configuredLines[0].getLabel() != tempLine.getOperand()) {
                        tempLine.setError("***** Invalid operand");
                    }
                }
            }
        }
    } else if (line.size() == 3) {
        if (operations.checkOperation(line[0])) {
            tempLine.setError("***** Invalid Label");
        }
        tempLine.setLabel(line[0]);
        if (!operations.checkOperation(line[1])) {
            tempLine.setOpCode(line[1]);
            tempLine.setError("***** unrecognized operation code");
            tempLine.setOperand(line[2]);

        } else {
            tempLine.setOpCode(line[1]);
            OpGroups *opGroups = operations.checkOperation(line[1]);
            if ((*opGroups).checkOperand(line[2], line[1])) {
                tempLine.setOperand(line[2]);
                if((*opGroups).getSize()==2)
                {
                    tempLine.setFormatNo(2);
                } else
                {
                    if ( (tempLine.getOpCode())[0] =='+' )
                    {
                        tempLine.setFormatNo(4);
                    }
                    else
                    {
                        tempLine.setFormatNo(3);
                    }

                }
            } else {
                tempLine.setOperand(line[2]);
                tempLine.setError("***** Invalid operand");
            }
        }
    }
    configuredLines.push_back(tempLine);

    /***************************************************Literals*********************/
    if (tempLine.getOperand().find_first_of('=')==0)
    {
        string name = tempLine.getOperand();
        string hexValue="";
        if (name[1]=='C')
        {
            for (int i=3;i<name.size()-1;i++)
            {
                std::ostringstream ss;
                ss << std::hex << (int) name[i];
                string temp="";
                for (char ch : ss.str())
                {
                    ch = toupper(ch);
                    hexValue = hexValue + ch;
                }
            }
        }
        else if (name[1] == 'X')
        {
            for (int i=3;i<name.size()-1;i++)
            {
                hexValue = hexValue + name[i];
            }
        }
        if (name[1]=='W')
        {
            int value ;
            string valueStr;
            for (int i=3;i<name.size()-1;i++)
            {
                valueStr+=name [i];
            }
            /********************CONVERTING String TO DECIMAL Integer *******/
            std::istringstream(valueStr) >> std::dec >> value;
            /********************CONVERTING DECIMAL TO HEX *******/
            std::ostringstream ss;
            ss << std::hex <<value;
            for (char ch : ss.str())
            {
                ch = toupper(ch);
                hexValue = hexValue + ch;
            }
        }

        if (litTab.find(hexValue) == litTab.end())
        {
            Literal tempLiteral;
            tempLiteral.setName(name);
            tempLiteral.setHexValue(hexValue);
            tempLiteral.setPrinted(false);
            litTab[hexValue]=tempLiteral;
        }
    }

    if (tempLine.getOpCode()=="LTORG" || tempLine.getOpCode()=="END")
    {
        for (map<string,Literal>::iterator it=litTab.begin(); it!=litTab.end(); ++it)
        {
            if (! it->second.isPrinted())
            {
                it->second.setPrinted(true);
                Line temp;
                temp.setLabel("*");
                temp.setOpCode((it->second).getName());
                configuredLines.push_back(temp);
            }
        }
    }
}


