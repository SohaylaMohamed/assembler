//
// Created by HP on 6/10/2018.
//

#include <fstream>
#include "pass2.h"
#include "object_code.h"

const int MAX_SIZE = 60;

vector<string> pass2::generateObjectCode(vector<Line> lines) {
    int format;
    SymTable symTable;
    symTable.createSymTable(lines);
    object_code calculate = object_code(symTable);
    vector<string> objectCodes;
    regex regex1("^=[cCwWxX]");
    for (int i = 0; i < lines.size(); ++i) {
        format = lines[i].getFormatNo();
        switch (format) {
            case 1:
                objectCodes.push_back(calculate.getObject_1(lines[i]));
                break;
            case 2:
                objectCodes.push_back(calculate.getObject_2(lines[i]));
                break;
            case 3:
            case 4:
                objectCodes.push_back(calculate.getObject_3(lines[i]));
                break;
            case 0 :
                Line line = lines[i];
                if (line.getOpCode() == "WORD" || line.getOpCode() == "BYTE") {
                    vector<string> codes = calculate.getObject_dir(line);
                    for (int j = 0; j < codes.size(); ++j) {
                        objectCodes.push_back(codes[j]);
                    }
                } else if (regex_match(line.getOpCode(), regex1)) {
                    objectCodes.push_back(calculate.getObject_lit(line));
                }
                break;
        }
    }
}

void pass2::printObjectProgam(vector<string> objectCode, vector<Line> lines) {
    ofstream outFile;
    outFile.open("objectProgram.txt");
    if (outFile.is_open()) {
        string zeros = "00";
        string start_address = lines[0].getAddress();
        start_address = zeros + start_address;
        string end_address = lines[lines.size() - 1].getAddress();
        end_address = zeros + end_address;
        string program_name = "";
        if (lines[0].getLabel().size() != 0) {
            program_name = lines[0].getLabel();
            outFile << "H^" << program_name << "^" << start_address << "^" << end_address;
            outFile << " \n";
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Operations operations;
        //TODO: CHECK LITERALS
        for (int i = 0; i < lines.size(); i++) {
            if (operations.checkOperation(lines[i].getOpCode())->getSize() == 0) {
                continue;
            }
            string recordStartAddress = lines[i].getAddress();
            string recordEndAddress = "";
            vector<string> recordObjectCodes;
            int recInstSize = 0;
            bool done = false;
            while (!done) {
                if (lines[i].getOpCode() == "WORD" || lines[i].getOpCode() == "BYTE") {
                    int numberOfOperands = calculateNumOfOperands(lines[i].getOperand());
                    int d = i;
                    for (int k = 0; k < numberOfOperands; ++k) {
                        recInstSize = recInstSize + objectCode[d].length();
                        if (recInstSize > MAX_SIZE) {
                            recordEndAddress = lines[i].getAddress();
                            done = true;
                            i--;
                            break;
                        }
                        d++;
                    }

                    if (!done) {
                        for (int k = 0; k < numberOfOperands; ++k) {
                            recordObjectCodes.push_back(objectCode[i]);
                            i++;
                        }
                        i--;
                    }

                } else {
                    recInstSize = recInstSize + objectCode[i].length();
                    if (recInstSize <= MAX_SIZE) {
                        recordObjectCodes.push_back(objectCode[i]);
                    } else {
                        recordEndAddress = lines[i].getAddress();
                        done = true;
                        i--;
                    }
                }
            }
            int startAddr;
            int endAddr;
            std::istringstream(start_address) >> std::hex >> startAddr;
            std::istringstream(recordEndAddress) >> std::hex >> endAddr;
            int recordSize = endAddr - startAddr;
            std::ostringstream ss;
            ss << std::hex << recordSize;
            outFile << "T^" << start_address << "^" << ss.str();
            for (int j = 0; j < recordObjectCodes.size(); j++) {
                outFile << "^" << recordObjectCodes[j];
            }
            outFile << "\n";
        }
        ////////////////////////////////////////////////////////////////////////////////////
        for (int j = 0; j < lines.size(); ++j) {
            if (lines[j].getFormatNo() == 4) {
                int addr;
                std::istringstream(lines[j].getAddress()) >> std::hex >> addr;
                addr = addr + 1;
                std::ostringstream ss;
                ss << std::hex << addr;
                string address = ss.str();
                address = zeros + address;
                outFile << "M^" << address << "^05+" << program_name;
                outFile << " \n";
            }

        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////
        outFile << "E^" << start_address;
        outFile << " \n";

    }
}

int pass2::toInt(string number) {
    stringstream geek(number);
    int x = 0;
    geek >> x;
    return x;
}

int pass2::calculateNumOfOperands(const string &operand) {
    std::vector<std::string> seglist;
    if (operand.find_first_of(',') != -1) {
        std::stringstream test(operand);
        std::string segment;
        while (std::getline(test, segment, ',')) {
            seglist.push_back(segment);
        }
        return seglist.size();
    } else {
        return 1;
    }
}
