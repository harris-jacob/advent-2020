#include <istream>

#include "day_16.hpp"
#include "gtest/gtest.h"

TEST(day_16, partOne) {

  // Arrange
  std::istringstream input(
        "class: 0-1 or 4-19\n"
        "row: 0-5 or 8-19\n"
        "seat: 0-13 or 16-19\n"
        "\n"
        "your ticket:\n"
        "11,12,13\n"
        "\n"
        "nearby tickets:\n"
        "3,9,18\n"
        "15,1,5\n"
        "5,14,9\n"

  );

  auto solution = day16::Day16();

  // Assert
  EXPECT_EQ(solution.partTwo(input), "71");
}
