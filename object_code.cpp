//
// Created by HP on 6/9/2018.
//

#include <iomanip>
#include "object_code.h"
#include "Operations.h"
#include "Registers.h"
//TODO : CHECK IF PASS1 IS WITHOUT ERRORS BEFORE PASS2
//TODO :ERRORS
//TODO : LITERALS AND EXPRESSIONS
//TODO : CHECK KOL ELE ANA KATBAH 3LSHAN KONT NAYMA T2REBAN W 3'YRT 7AGAT
//TODO : FINAL VALUE
//TODO : WORD / BYTE
//TODO : NO OBJECT CODE GROUP
//TODO : CHECK BASE AND REGISTER X


using namespace std;
const int PC_U_BOUND = 2047;
const int PC_L_BOUND = -2048;
const int B_BOUND = 4095;
//zwdt el operations w el registers hna et2kdo en keda el pointers sa7
//TODO : FEE MOSHKLA F BUILDING EL REGISTERS ANA MESH 3ARFA A7LHA "UNDEFINED REFERNCE"
object_code::object_code(SymTable symTable1) {
    object_code::symTable = symTable1;
    object_code::operations.readOperations();
    object_code::registers.readRegisters();
}
//format 1
std::string object_code::getObject_1(Line line) {
    string operation = line.getOpCode();
    OpGroups *group = operations.checkOperation(operation);
    string opCode = group->getOperationObCode(operation);
    return toHex(opCode,8);
}
//format 2
//ss to convert decimal to string
std::string object_code::getObject_2(Line line) {
    string operation = line.getOpCode();
    OpGroups *group = operations.checkOperation(operation);
    string operand = line.getOperand();
    stringstream ss;
    string target;
    ss << operand.at(0);
    ss >> target;
    int r1 = registers.getRegNum(target);
    ss << operand.at(2);
    ss >> target;
    int r2 = registers.getRegNum(target);
    string opCode = group->getOperationObCode(operation);
    //return toHex(opCode,8).append(to_string(r1)).append(to_string(r2));
    return"" ;
}
//format 3 & 4
std::string object_code::getObject_3(Line line) {
    string operation = line.getOpCode();
    //check format
    if (operation.at(0) == '+') {
        //format 4
        string address; //target address no relative here
        bitset<6> flags(1); //1 for e
        string operand = line.getOperand();
        char first = operand.at(0);
        //check mode (indirect / immediate / direct)
        switch (first) {
            case '@' : { //indirect
                flags.flip(5); //flip n
                string r = "[a-fA-F0-9]+";//check hex value
                regex reg(r);
                operand = operand.substr(1, operand.size() - 1);
                if (regex_match(operand, reg)) {
                    if(!symTable.findElement(operand)) { //check if no operand with name
                        address = operand; //if operand is hex value
                    } else {
                        address = symTable.getElementAddress(operand);
                    }
                } else {
                    address = symTable.getElementAddress(operand);
                }
            }
                break;
            case '#': {
                flags.flip(4);
                string r = "[0-9]+";
                regex regex1(r);
                operand = operand.substr(1, operand.size() - 1);
                if (regex_match(operand, regex1)) {
                    address = object_code::toHex(bitset<20>(operand).to_string(),5);
                } else { // invalid or wrong operand
                    address = symTable.getElementAddress(operand);
                }
            }
                break;
            default:
                //check index x
                string indexReg = "[A-Za-z0-9]+\\,[xX]";
                regex reg(indexReg);
                if (regex_match(operand, reg)) {
                    //TODO : contents of x register.
                } else {
                    string r = "[A-Fa-f0-9]+";
                    regex reg2(r);
                    if (regex_match(operand, reg2)) {
                        if(!symTable.findElement(operand)) { //check if no operand with name
                            address = operand; //if operand is hex value
                        } else {
                            address = symTable.getElementAddress(operand);
                        }
                    } else {
                        address = symTable.getElementAddress(operand);
                    }
                }

                break;
        }


        //format 3
        } else {
        bitset<6> flags(0);
        bitset<12> disp(0);
        string operand = line.getOperand();
        char first = operand.at(0);
        switch (first) {
            case '@' : {
                //TODO : disp value after calculations
                flags.flip(5);
                string r = "[a-fA-F0-9]+";
                regex reg(r);
                operand = operand.substr(1, operand.size() - 1);
                if (regex_match(operand, reg)) {
                    if(!symTable.findElement(operand)) { //check if no operand with name
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
                    //to binary from hex decimal to binary
                    //operand is decinal
                    disp = bitset<12>(operand);
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
                string indexReg = "[A-Za-z0-9]+\\,[xX]";
                regex reg(indexReg);
                if (regex_match(operand, reg)) {
                    //contents of x register.
                } else {
                    //relative pc first
                    string address = symTable.getElementAddress(operand);
                    int elementAddress = 0;
                    std::istringstream(address) >> std::hex >> elementAddress;
                    int lc = 0;
                    std::istringstream(line.getAddress()) >> std::hex >> lc;
                    lc = lc + 3;
                    int TA = lc - elementAddress;
                    //check bounds
                    bool pc_relative = pc_check_bounds(TA);
                    if (~pc_relative) {
                        //base
                    } else {
                        flags.flip(1);
                        //TA decimal to binary into disp bits
                    }
                }
                break;
        }
        OpGroups *group = operations.checkOperation(operation);
        string opCode = group->getOperationObCode(operation);
        opCode = opCode.substr(0, opCode.size() - 2);
        string obcode = opCode.append(flags.to_string()).append(disp.to_string());
    }

}

string object_code::toHex(string binary, int bits) {
    string bin(binary);
    int result = 0;

    for (size_t count = 0; count < bin.length(); ++count) {
        result *= 2;
        result += bin[count] == '1' ? 1 : 0;
    }

    stringstream ss;
    ss << hex << setw(bits) << setfill('0') << result;

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
