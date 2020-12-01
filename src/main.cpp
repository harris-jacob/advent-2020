#include "day_1.hpp"
#include "read_file.hpp"

#include <iostream>
#include <string>
#include <vector>

const std::string _INPUT_DIR = "../input/";

void dayOneSolution() {
  // Load
  auto input = utils::readInput("../../input/day_01.txt");
  // Part one
  std::cout << day1::partOne(input) << "\n";
  // Part two
  std::cout << day1::partTwo(input) << "\n";
}

// TODO big ole switch here
int main() {

}