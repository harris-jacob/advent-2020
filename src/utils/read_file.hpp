#pragma once

#include <istream>
#include <string>
#include <vector>

namespace utils {

// Read file containing line separated ints and return as vector
std::vector<int> readIntInput(std::istream& infile);

// Read file containing line separated longs and returns as vector 
std::vector<long> readLongInput(std::istream& infile);

// Read file of strings by line and return as vector.
std::vector<std::string> readStrInput(std::istream& infile);

// Read a file of blank line delimeters and return as vector.
std::vector<std::string> readLnDelimiterInput(std::istream& infile);

} // namespace utils
