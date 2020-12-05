#include "read_file.hpp"
#include <string>
#include <vector>

namespace utils {

std::vector<int> readIntInput(std::istream& infile) {;
  std::vector<int> input{};
  int a;

  while (infile >> a) {
    input.push_back(a);
  }

  return input;
}

std::vector<std::string> readStrInput(std::istream& infile) {
  std::string line;
  std::vector<std::string> input{};
  while (std::getline(infile, line)) {
  // Annoying edge case if files are created on windows machine
  if (!line.empty() && line[line.size() - 1] == '\r') {
    line.erase(line.size() - 1);
  }
    input.push_back(line);
  }


  return input;
}

} // namespace utils