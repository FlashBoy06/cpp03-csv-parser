# Simple C++03 CSV Parser

A lightweight, zero-dependency CSV parser implementation compatible with the C++03 standard. Designed for legacy system support and educational purposes.

## Features

- C++03 Compatible: Works with older compilers and legacy infrastructure.
- Zero Dependencies: Uses only the Standard Template Library (vector, string, fstream).
- Modular Design: Clean separation between interface (.h) and implementation (.cpp).
- Memory Efficient: Uses standard vectors for dynamic field storage.

## Integration

Simply include the cpp_csv_parser.h and cpp_csv_parser.cpp files in your project.

## Project Structure

- src/ main.cpp: Entry point
- cpp_csv_parser.cpp: Implementation logic
- cpp_csv_parser.h: Class definitions
- test.csv: Sample data for testing

## Roadmap

- [x] RFC 4180 Compliance: Implement logic to handle commas inside quotes.

- Custom Delimiters: Support for semicolons or tabs.

- Error Handling: Robust checks for malformed lines.

## License

This project is open source and available under the MIT License.
