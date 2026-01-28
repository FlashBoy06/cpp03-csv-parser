#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class CsvRow {
private:
    std::vector<std::string> tokens;

public:
    void parse_line(std::string line);
    void toString();
};

bool file_open(std::fstream& file);

#endif

