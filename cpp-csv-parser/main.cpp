#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cpp_csv_parser.h"

int main()
{
    std::fstream file;
    file_open(file);
    std::string line;

    while (std::getline(file, line)) {
        CsvRow row('\t');
        row.parse_line(line);
        row.toString();
    }
    file.close();
    return 0;
}
