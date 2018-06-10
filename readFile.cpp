#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <sstream>
#include "readFile.h"

using namespace std;

readFile::readFile(string fileName) {
    readFile::fileName = fileName;
}
void readFile::read() {

    lineVector.reserve(30);
    allLines.reserve(30);
    //Todo Parameter type mismatch
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "File Doesn't Exist!" << endl;
        return;
    }
    while (inFile.good()) {
        string thesub,cstring="";
        lineVector.clear();
        getline(inFile, line);
        if (Blank())
            continue;
        if (comment()) {
            lineVector.push_back(line);
            allLines.push_back(lineVector);
            continue;
        }
        if (Stringwithoutequal()){
            int found=line.find_first_of('\'')-1;
            int sizestr=line.size();
            cstring = line.substr(found, sizestr);
            line.erase(found, sizestr);
        }
        if (Stringwithequal()){
            int found=line.find_first_of('\'')-2;
            int sizestr=line.size();
            cstring = line.substr(found, sizestr);
            line.erase(found, sizestr);
        }
        if((line.find_first_of('*') != -1)&& (line.at(line.find_first_of('*')-1) == ' ')){
            int found=line.find_first_of('*');
            int sizestr=line.size();
            thesub = line.substr(found, sizestr);
            line.erase(found, sizestr);
        }
        std::istringstream iss(line);
        for(std::string line; iss >> line; )
            lineVector.push_back(line);
        if(thesub != "") {
            lineVector.push_back(thesub);
        }
        if(cstring != "") {
            lineVector.push_back(cstring);
        }
        allLines.push_back(lineVector);
    }
    inFile.close();

}

bool readFile::comment() {
    regex Comment("^\\s*\\..*");
    return regex_match(line, Comment);
}
vector<vector<string>> readFile::getLines() {
    return allLines;
}

bool readFile::Blank() {
    regex blank("\\s*");
    return regex_match(line, blank);
}
bool readFile::Stringwithoutequal() {
    regex cSrt("(^[a-zA-Z0-9\\s]+[cC]\\'[a-zA-Z0-9\\s]+\\'\\s*)| (^[a-zA-Z0-9\\s]+[cC]\\'\\s(.*)\\'\\s*)");
    regex xSrt("(^[a-zA-Z0-9\\s]+[xX]\\'[a-zA-Z0-9\\s]+\\'\\s*)| (^[a-zA-Z0-9\\s]+[xX]\\'\\s(.*)\\'\\s*)");
    if(regex_match(line, cSrt)){
        return true;
    }
    if(regex_match(line, xSrt)){
        return true;
    }
    return false;
}
bool readFile::Stringwithequal() {
    regex cSrt("(^[a-zA-Z0-9\\s]+[=][cC]\\'[a-zA-Z0-9\\s]+\\'\\s*)| (^[a-zA-Z0-9\\s]+[=][cC]\\'\\s(.*)\\'\\s*)");
    regex xSrt("(^[a-zA-Z0-9\\s]+[=][xX]\\'[a-zA-Z0-9\\s]+\\'\\s*)| (^[a-zA-Z0-9\\s]+[=][xX]\\'\\s(.*)\\'\\s*)");
    regex wSrt("(^[a-zA-Z0-9\\s]+[=][wW]\\'[a-zA-Z0-9\\s]+\\'\\s*)| (^[a-zA-Z0-9\\s]+[=][wW]\\'\\s(.*)\\'\\s*)");
    if(regex_match(line, cSrt)){
        return true;
    }
    if(regex_match(line, xSrt)){
        return true;
    }
    if(regex_match(line, wSrt)){
        return true;
    }
    return false;
}