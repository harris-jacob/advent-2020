#include <istream>

#include "day_14.hpp"
#include "gtest/gtest.h"

namespace test {

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
        "mask = 000000000000000000000000000000X1001X\n"
        "mem[42] = 100\n"
        "mask = 00000000000000000000000000000000X0XX\n"
        "mem[26] = 1\n"
  );

  auto solution = day14::Day14();

  // Assert
  EXPECT_EQ(solution.partTwo(input), "208");

}

} // namespace test