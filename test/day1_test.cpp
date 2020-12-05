#include "day_1.hpp"
#include "read_file.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <fstream>
#include <vector>

namespace test {

auto input_path = "./input/day_1.txt";

TEST(day_1, loadInput) {
  std::ifstream infile(input_path);
  std::vector<int> input = utils::readIntInput(infile);
  EXPECT_EQ(input[0], 2000);
}

TEST(day_1, partOne) {
  // Arrange
  std::istringstream input("1721\n979\n366\n299\n675\n1456");
  auto solution = day1::Day1();

  // Act/Assert
  EXPECT_EQ(solution.partOne(input), "514579");


}

TEST(day_1, partTwo) {
  // Arrange
  std::istringstream input("1721\n979\n366\n299\n675\n1456");
  auto solution = day1::Day1();

  // Act/Assert
  EXPECT_EQ(solution.partTwo(input), "241861950");
}

} // namespace test
