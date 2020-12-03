#include "day_1.hpp"
#include "day_2.hpp"
#include "day_3.hpp"
#include "read_file.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// TODO figure out how to not make this depend on the working dir.
const std::string _INPUT_DIR = "./input/";

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

void dayTwoSolution() {
  // Load
  std::ifstream infile(_INPUT_DIR + "day_2.txt");
  auto input = utils::readStrInput(infile);
  
  std::cout << "Day 2: \n";

  // Part one
  std::cout << "  - part 1: " << day2::partOne(input) << "\n";

  // Part two
  std::cout << "  - part 2: " << day2::partTwo(input) << "\n";
}

void dayThreeSolution() {
    // Load
  std::ifstream infile(_INPUT_DIR + "day_3.txt");
  auto input = utils::readStrInput(infile);
  
  std::cout << "Day 3: \n";

  // Part one
  std::cout << "  - part 1: " << day3::partOne(input) << "\n";

    // Part one
  std::cout << "  - part 2: " << day3::partTwo(input) << "\n";
}

// TODO big ole switch here
int main() { dayThreeSolution(); }