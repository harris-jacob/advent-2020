#include "day_1.hpp"
#include "read_file.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

namespace test {

auto input_path = "../../input/day_01.txt";

TEST(day_1, loadInput) {
  std::vector<int> input = utils::readInput(input_path);
  EXPECT_EQ(input[0], 2000);
}

TEST(day_1, partOne) {
  // Arrange
  std::vector<int> input{1721, 979, 366, 299, 675, 1456};

  // Assert
  EXPECT_EQ(day1::partOne(input), 514579);
}

TEST(day_1, partTwo) { // Arrange
  std::vector<int> input{1721, 979, 366, 299, 675, 1456};
} // namespace test

} // namespace test
