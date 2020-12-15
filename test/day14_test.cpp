#include <istream>

#include "day_14.hpp"
#include "gtest/gtest.h"

TEST(day_14, partOne) {

  // Arrange
  std::istringstream input(
        "mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X\n"
        "mem[8] = 11\n"
        "mem[7] = 101\n"
        "mem[8] = 0\n"
  );

  auto solution = day14::Day14();

  // Assert
  EXPECT_EQ(solution.partOne(input), "165");
}

TEST(day_14, partTwo) {

  // Arrange
  std::istringstream input(
    "mask = X00001010X0010101X00101X001010XX0010\n"
    "mem[1234] = 5678\n"
  );

  auto solution = day14::Day14();

  // Assert
  EXPECT_EQ(solution.partTwo(input), "508032");

}