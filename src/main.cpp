#include "day_1.hpp"
#include "read_file.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const std::string _INPUT_DIR = "../../input/";

void dayOneSolution() {
  // Load
  std::ifstream infile(_INPUT_DIR + "day_1.txt");
  auto input = utils::readIntInput(infile);

  std::cout << "Day 1: \n";

  // Part one
  std::cout << "  - part 1: " << day1::partOne(input) << "\n";
  // Part two
  std::cout << "  - part 2: " << day1::partTwo(input) << "\n";
}

// TODO big ole switch here
int main() { dayOneSolution(); }