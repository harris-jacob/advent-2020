#pragma once

#include <istream>
#include <string>
#include <vector>

namespace utils {

// Read file containing line separated ints and return as vector
std::vector<int> readIntInput(std::istream& infile);

// Read file of strings by line and return as vector.
std::vector<std::string> readStrInput(std::istream& infile);

} // namespace utils
