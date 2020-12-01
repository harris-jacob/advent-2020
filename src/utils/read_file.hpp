#include <fstream>
#include <string>
#include <vector>

namespace utils {

std::vector<int> readInput(std::string path) {
  std::ifstream infile(path);
  std::vector<int> input{};
  int a;

  while (infile >> a) {
    input.push_back(a);
  }

  return input;
}
} // namespace utils