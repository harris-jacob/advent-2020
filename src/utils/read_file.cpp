#include "read_file.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace utils {

std::vector<int> readIntInput(std::string path) {
  std::ifstream infile(path);
  std::vector<int> input{};
  int a;

  while (infile >> a) {
    input.push_back(a);
  }

  return input;
}

std::vector<std::string> readStrInput(const std::string path) {
  std::string line;
  std::vector<std::string> input{};
  std::ifstream infile(path);
  while (std::getline(infile, line)) {
    input.push_back(line);
  }
}

} // namespace utils