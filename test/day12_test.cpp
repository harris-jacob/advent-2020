#include <istream>

#include "gtest/gtest.h"
#include "day_12.hpp"

TEST(day_12, partOne) {

      // Arrange
      std::istringstream input(
          "F10\n"
          "N3\n"
          "F7\n"
          "R90\n"
          "F11\n"
  );

    auto solution = day12::Day12();

    // Assert
    EXPECT_EQ(solution.partOne(input), "25");
}

TEST(day_12, partTwo) {

      // Arrange
      std::istringstream input(
          "F10\n"
          "N3\n"
          "F7\n"
          "R90\n"
          "F11\n"
  );

    auto solution = day12::Day12();

    // Assert
    EXPECT_EQ(solution.partTwo(input), "286");
}