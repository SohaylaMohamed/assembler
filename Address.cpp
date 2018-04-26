//
// Created by karim on 4/25/2018.
//

#include "Address.h"
#include "Line.h"
#include "Operations.h"
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

void Address::setAddresses(vector<Line> configuredLines) {
    Operations operations;
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
    while (configuredLines[i].getOpCode() != "END") {
        Line currentLine = configuredLines[i];
        if (currentLine.getComment() == NULL) {
            string currentLineOpcode = currentLine.getOpCode();
            OpGroups *opGroups = operations.checkOperation(currentLineOpcode);
            if (opGroups != NULL) {
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
                //Todo for  C'test string' , locCTR +=13

            } else
                currentLine.setOpCode("INVALID");
        }
        i++;
        /********************CONVERTING DECIMAL TO HEX *******/
        std::ostringstream ss;
        ss << std::hex << locCRT;
        string address = ss.str();
        addresses.push_back(address);
    }
};