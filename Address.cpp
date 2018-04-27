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

vector<string> Address::setAddresses(vector<Line> configuredLines) {
    Operations operations;
    operations.readOperations();
    int locCRT = 0;
    string firstLineOpCode = configuredLines[0].getOpCode();
    string firstLineOperand = configuredLines[0].getOperand();
    if (firstLineOpCode == "START") {
        if (firstLineOperand != "INVALID") {
            /********************CONVERTING HEX TO DECIMAL *******/
            std::istringstream(firstLineOperand) >> std::hex >> locCRT;
        }
        //Todo make a converting function instead of repeated code
        /********************CONVERTING DECIMAL TO HEX *******/
        std::ostringstream ss;
        ss << std::hex << locCRT;
        string address = ss.str();
        addresses.push_back(address);
    }
    /********************CONVERTING DECIMAL TO HEX *******/
    std::ostringstream ss;
    ss << std::hex << locCRT;
    string address = ss.str();
    addresses.push_back(address);
    int i = 1;
    //Todo if current line is a comment put empty address
    while (configuredLines[i].getOpCode() != "END") {
        Line currentLine = configuredLines[i];
        if (currentLine.getOpCode() != "INVALID") {
            string currentLineOpcode = currentLine.getOpCode();
            OpGroups *opGroups = operations.checkOperation(currentLineOpcode);
            if (opGroups->getSize()!=0) {
                //todo ask if getSize() returns the instruction length
                locCRT += opGroups->getSize();
            } else if (currentLineOpcode == "WORD") {
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
                //Todo for  C'test string' , locCTR +=13 , X'05' ,locCRT +=1
                string currentLineOperand = currentLine.getOperand();
                 if (currentLineOperand[0] == 'X')
                 {
                     if (currentLineOperand[1] == '\'' && currentLineOperand[currentLineOperand.size()-1] == '\'')
                        locCRT += 1;
                     else
                         currentLine.setOperand("INVALID");
                 }
                 else if (currentLineOperand[0]=='C')
                 {
                     if (currentLineOperand[1] == '\'' && currentLineOperand[currentLineOperand.size()-1] == '\'')
                     {
                         locCRT += (currentLineOperand.size()-1)-2;
                     }
                     else
                         currentLine.setOperand("INVALID");
                 }
            } else
                currentLine.setOpCode("INVALID");
        }
        else
        {
            std::ostringstream ss;
            ss << std::hex << locCRT;
            string address = ss.str();
            addresses.push_back(address);
        }
        i++;
        /********************CONVERTING DECIMAL TO HEX *******/
        std::ostringstream ss;
        ss << std::hex << locCRT;
        string address = ss.str();
        addresses.push_back(address);
    }

    return addresses;
};