#include "day_1.hpp"
#include "read_file.hpp"

#include <iostream>
#include <string>
#include <vector>

const std::string _INPUT_DIR = "input/";

void dayOneSolution() {
  // Load
  auto input = utils::readIntInput(_INPUT_DIR + "day_1.txt");
  std::cout << input.size() << "\n";
  // Part one
  std::cout << day1::partOne(input) << "\n";
  // Part two
  std::cout << day1::partTwo(input) << "\n";
}

// TODO big ole switch here
int main() { dayOneSolution(); }