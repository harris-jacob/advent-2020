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

std::vector<std::string> readLnDelimiterInput(std::istream& infile) {
  std::string line;
  std::string item;
  std::vector<std::string> items;

  while(std::getline(infile, line)) {
    
    if(line.empty()) {
      items.push_back(item);
      item.clear();
      continue;
    }

    if(item.length() > 0) {
      item.push_back(' ');
    }

    item += line;

  }

  // last one has no newline
  items.push_back(item);

  return items;
}

} // namespace utils