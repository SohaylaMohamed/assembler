//
// Created by karim on 4/25/2018.
//
#include <iostream>
#include "Address.h"
#include "Line.h"
#include "Operations.h"
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <regex>
using namespace std;

Address::Address() {}

vector<Line> Address::setAddresses(vector<Line> configuredLines ) {
    Operations operations;
    operations.readOperations();
    int locCRT = 0;
    string firstLineOpCode = configuredLines[0].getOpCode();
    string firstLineOperand = configuredLines[0].getOperand();
    int i = 0 ;
    if (firstLineOpCode == "START") {
        i++;
        if (!firstLineOperand.empty()) {
            /********************CONVERTING HEX TO DECIMAL *******/
            std::istringstream(firstLineOperand) >> std::hex >> locCRT;
        }

        /********************CONVERTING DECIMAL TO HEX *******/
        std::ostringstream ss;
        ss << std::hex << locCRT;
        string address = ss.str();
        addresses.push_back(address);
        configuredLines[0].setAddress(address);
    }
    else
    {
        while (configuredLines[i].getOpCode() != "START")
        {
            i++;
            if (configuredLines[i].getOpCode() == "START") {
                if (!configuredLines[i].getOperand().empty()) {
                    /********************CONVERTING HEX TO DECIMAL *******/
                    std::istringstream(configuredLines[i].getOperand()) >> std::hex >> locCRT;
                }
                /********************CONVERTING DECIMAL TO HEX *******/
                std::ostringstream ss;
                ss << std::hex << locCRT;
                string address = ss.str();
                addresses.push_back(address);
                configuredLines[i].setAddress(address);
                break;
            }
        }
    }

    /********************CONVERTING DECIMAL TO HEX *******/
    std::ostringstream ss;
    ss << std::hex << locCRT;
    string address = ss.str();
    addresses.push_back(address);
    configuredLines[i].setAddress(address);
    //Todo if current line is a comment put empty address

    for (int i=1;i<configuredLines.size()-1;i++) {
        Line currentLine = configuredLines[i];
        if (currentLine.getComment().find_first_of(".") == -1) {
            string currentLineOpcode = currentLine.getOpCode();
            OpGroups *opGroups = operations.checkOperation(currentLineOpcode);

            if (currentLineOpcode == "WORD") {
                locCRT += 3;
            } else if (currentLineOpcode == "RESW") {
                int integerOperand;
                if (!(istringstream(currentLine.getOperand()) >> integerOperand)) integerOperand = 0;
                locCRT += 3 * integerOperand;
            } else if (currentLineOpcode == "RESB") {
                int integerOperand;
                if (!(istringstream(currentLine.getOperand()) >> integerOperand)) integerOperand = 0;
                locCRT += integerOperand;
            } else if (currentLineOpcode == "BYTE") {
                string currentLineOperand = currentLine.getOperand();
                if (currentLineOperand[0] == 'X')
                {
                    if (currentLineOperand[1] == '\'' && currentLineOperand[currentLineOperand.size()-1] == '\'')
                    {
                        if (!(((currentLineOperand.size()-1)-2) %2))
                        {
                            locCRT += ((currentLineOperand.size()-1)-2) /2;
                        }
                        else
                            configuredLines[i].setError("*****Invalid operand length");
                    }
                    else {
                        configuredLines[i].setError("*****Invalid operand");
                    }
                }
                else if (currentLineOperand[0]=='C')
                {
                    if (currentLineOperand[1] == '\'' && currentLineOperand[currentLineOperand.size()-1] == '\'')
                    {
                        locCRT += (currentLineOperand.size()-1)-2;
                    }
                    else
                        configuredLines[i].setError("*****Invalid operand");
                }
            }
            else if(currentLineOpcode == "ORG"){
                int integerOperand;
                bool flag =false;
                if (!(istringstream(currentLine.getOperand()) >> integerOperand)) {
                    for (int j = i-1; j >=0 ; --j) {
                        if (configuredLines[j].getLabel() == currentLine.getOperand()){
                            std::istringstream(configuredLines[j].getAddress()) >> std::hex >> locCRT;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        configuredLines[i].setError("*****Invalid operand");
                    }
                }
                else {
                    locCRT = integerOperand;
                }
            }

            else if (opGroups != NULL && opGroups->getSize()!=0) {
                //todo ask if getSize() returns the instruction length
                locCRT += opGroups->getSize();
            }

            /***Literals***/
            else if (currentLineOpcode[0]=='=')
            {
                if (currentLineOpcode[1]=='X')
                {
                    if (currentLineOpcode[2] == '\'' && currentLineOpcode[currentLineOpcode.size()-1] == '\'')
                    {
                        if (!(((currentLineOpcode.size()-1)-3) %2))
                        {
                            locCRT += ((currentLineOpcode.size()-1)-3) /2;
                        }
                        else
                            configuredLines[i].setError("*****Invalid operand length");
                    }
                    else {
                        configuredLines[i].setError("*****Invalid operand");
                    }
                }
                else if (currentLineOpcode[1]=='C')
                {
                    if (currentLineOpcode[2] == '\'' && currentLineOpcode[currentLineOpcode.size()-1] == '\'')
                    {
                        locCRT += (currentLineOpcode.size()-1)-3;
                    }
                    else
                        configuredLines[i].setError("*****Invalid operand");
                }
                else if (currentLineOpcode[1]=='W')
                {
                    locCRT += 3;
                }
            }

            else
            {
                std::istringstream(configuredLines[i].getAddress()) >> std::hex >> locCRT;
            }
        }
        /********************CONVERTING DECIMAL TO HEX *******/
        std::ostringstream ss;
        ss << std::hex << locCRT;
        string address = ss.str();
        addresses.push_back(address);
        configuredLines[i+1].setAddress(address);
    }

    addresses.push_back("1");
    return configuredLines;
};