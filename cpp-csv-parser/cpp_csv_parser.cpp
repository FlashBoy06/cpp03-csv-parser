#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "cpp_csv_parser.h"

void CsvRow::parse_line(std::string line) {
    std::string token;
    while (line.find(",") != std::string::npos) {
        token = line.substr(0, line.find(","));
        tokens.push_back(token);
        line.erase(0, line.find(",") + 1);
    }
    token = line.substr(0, line.find(","));
    tokens.push_back(token);
}

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