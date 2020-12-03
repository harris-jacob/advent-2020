#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace utils {

// Read file containing line separated ints and return as vector
std::vector<int> readIntInput(std::ifstream& infile);

// Read file of strings by line and return as vector.
std::vector<std::string> readStrInput(std::ifstream& infile);

} // namespace utils
