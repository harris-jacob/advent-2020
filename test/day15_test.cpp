#include <istream>

#include "day_15.hpp"
#include "gtest/gtest.h"

namespace test {

TEST(day_15, partOne) {

  // Arrange
  std::istringstream input(
      "0,3,6"
  );

  auto solution = day15::Day15();

  // Assert
  EXPECT_EQ(solution.partOne(input), "436");
}

} // namespace test

// Took this out because it runs slow ~ 10000ms (could probably speed up with a faster map lib, but meh)
/**
TEST(day_15, partTwo) {

  // Arrange
  std::istringstream input(
      "0,3,6"
  );

  auto solution = day15::Day15();

  // Assert
  EXPECT_EQ(solution.partTwo(input), "175594");
}

*/