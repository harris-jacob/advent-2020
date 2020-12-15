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