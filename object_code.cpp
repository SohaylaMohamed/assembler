//
// Created by HP on 6/9/2018.
//

#include <iomanip>
#include "object_code.h"
#include "Operations.h"

using namespace std;
const int PC_U_BOUND = 2047;
const int PC_L_BOUND = -2048;
const int B_BOUND = 4095;

object_code::object_code(SymTable symTable1) {
    object_code::symTable = symTable1;
}
std::string object_code::getObject_1(Line line) {}
std::string object_code::getObject_2(Line line) {}

std::string object_code::getObject_3(Line line) {
    Operations operations;
    operations.readOperations();
    string operation = line.getOpCode();
    if (operation.find_first_of('+') != -1) {
        bitset<6> flags(1);


        //format4
    } else {
        bitset<6> flags(0);
        bitset<12> disp(0);
        string operand = line.getOperand();
        char first = operand.at(0);
        switch (first) {
            case '@' : {
                flags.flip(5);
                string r = "[0-9]+";
                regex reg(r);
                operand = operand.substr(1, operand.size() - 1);
                if (regex_match(operand, reg)) {
                    int lc = 0;
                    std::istringstream(line.getAddress()) >> std::hex >> lc;
                    lc = lc + 3;
                    int elementAddress = 0;
                    std::istringstream(operand) >> std::hex >> elementAddress;
                    int TA = lc - elementAddress;
                    bool pc_relative = pc_check_bounds(TA);
                    if (~pc_relative) {

                        int b = get_Base();
                        if (b == -1) {
                            //error
                        } else {
                            TA = b - elementAddress;
                            bool b_relative = b_check_bounds(TA);
                            if (!b_relative) {
                                //error
                            } else {
                                flags.flip(2);
                            }
                        }
                        //base
                    } else {
                        flags.flip(1);
                        //TA decimal to binary into disp bits
                    }
                } else {
                    string address = symTable.getElementAddress(operand);
                    int elementAddress = 0;
                    std::istringstream(address) >> std::hex >> elementAddress;
                    int lc = 0;
                    std::istringstream(line.getAddress()) >> std::hex >> lc;
                    lc = lc + 3;
                    int TA = lc - elementAddress;
                    bool pc_relative = pc_check_bounds(TA);
                    if (~pc_relative) {

                        int b = get_Base();
                        if (b == -1) {
                            //error
                        } else {
                            TA = b - elementAddress;
                            bool b_relative = b_check_bounds(TA);
                            if (!b_relative) {
                                //error
                            } else {
                                flags.flip(2);
                            }
                        }
                        //base
                    } else {
                        flags.flip(1);
                        //TA decimal to binary into disp bits
                    }
                }
            }

                break;
            case '#': {
                flags.flip(4);
                string r = "[0-9]+";
                regex regex1(r);
                operand = operand.substr(1, operand.size() - 1);
                if (regex_match(operand, regex1)) {
                    disp = object_code::toBinary(operand);
                } else { // invalid or wrong operand
                    string address = symTable.getElementAddress(operand);
                    int elementAddress = 0;
                    std::istringstream(address) >> std::hex >> elementAddress;
                    int lc = 0;
                    std::istringstream(line.getAddress()) >> std::hex >> lc;
                    lc = lc + 3;
                    int TA = lc - elementAddress;
                    bool pc_relative = pc_check_bounds(TA);
                    if (~pc_relative) {
                        //base
                    } else {
                        flags.flip(1);
                        //TA decimal to binary into disp bits
                    }
                }
            }
                break;
            default:
                //check index x
                //relative pc first
                //check bounds
                //check base if bounds are incorrect
                //base relative
                //calculate relative
                break;
        }
        OpGroups *group = operations.checkOperation(operation);
        string opCode = group->getOperationObCode(operation);
        opCode = opCode.substr(0, opCode.size() - 2);
        string obcode = opCode.append(flags.to_string()).append(disp.to_string());
    }

}

string object_code::toHex(string binary) {
    string bin(binary);
    int result = 0;

    for (size_t count = 0; count < bin.length(); ++count) {
        result *= 2;
        result += bin[count] == '1' ? 1 : 0;
    }

    stringstream ss;
    ss << hex << setw(6) << setfill('0') << result;

    string hexVal(ss.str());
    return hexVal;
}

bitset<12> object_code::toBinary(string hexNum) {
    stringstream ss;
    ss << hex << hexNum;
    unsigned n;
    ss >> n;
    bitset<12> b(n);
    return b;
}
std::string object_code::getObject_dir(Line line) {}

bool object_code::pc_check_bounds(int TA) {
    return TA <= PC_U_BOUND && TA >= PC_L_BOUND;
}


int object_code::get_Base() {
    if (base_Exist()) {

    }
    //check BASE opeation
    //get label BASE
    //check LDB & #label
    //check NOBASE occured before
    return -1;
}

bool object_code::b_check_bounds(int ta) {
    return ta > 0 && ta < B_BOUND;
}

bool object_code::base_Exist() {
    return false;
}
