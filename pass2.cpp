//
// Created by HP on 6/10/2018.
//

#include "pass2.h"
#include "object_code.h"

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

}