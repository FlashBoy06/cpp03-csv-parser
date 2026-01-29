#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "cpp_csv_parser.h"

void CsvRow::parse_line(std::string line) {
    std::string token = "";
    bool inQuotes = false;
    for (int i = 0; i < line.size(); i++) {
        switch (inQuotes) {
        case false:
            if (line[i] == '\"') { //in quotes
                inQuotes = true;
                break;
            }
            else if(line[i] == ','){ //end of token
                tokens.push_back(token);
                token = "";
            }
            else {  //add to token
                token += line[i];
            }
            break;
        case true:
            if (line[i] == '\"') { //quotes end -> end of token
                if (i + 1 < line.size() && line[i + 1] == '\"') {
                    token += '\"';
                    i++;           
                }
                else {
                    inQuotes = false;
                }
            }
            else{   //add to token
                token += line[i];
            }
            break;
        }
    }
    //add last saved token
    tokens.push_back(token);
}

//void CsvRow::parse_line(std::string line) {
//    std::string token;
//    while (line.find(",") != std::string::npos) {
//        token = line.substr(0, line.find(","));
//        tokens.push_back(token);
//        line.erase(0, line.find(",") + 1);
//    }
//    token = line.substr(0, line.find(","));
//    tokens.push_back(token);
//}

void CsvRow::toString() {
    for (size_t i = 0; i < tokens.size(); i++) {
        std::cout << "[" << tokens[i] << "] ";
    }
    std::cout << std::endl;
}

bool file_open(std::fstream& file) {
    file.open("test.csv", std::ios::in);
    if (!file.is_open()) {
        std::cout << "File cannot be opened!" << std::endl;
        return false;
    }
    return true;
}