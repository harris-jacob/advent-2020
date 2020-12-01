#include "day_1.hpp"
#include "read_file.hpp"

#include <iostream>
#include <string>
#include <vector>

const std::string _INPUT_DIR = "../input/";

// TODO big ole switch here
int main() {
  auto input = utils::readInput("../../input/day_01.txt");
  std::cout << day1::partOne(input) << "\n";
}