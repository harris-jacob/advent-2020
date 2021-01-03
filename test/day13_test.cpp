#include <istream>
#include "day_13.hpp"
#include "gtest/gtest.h"


namespace test {

TEST(day_13, partOne) {

  // Arrange
  std::istringstream input("939\n"
                           "7,13,x,x,59,x,31,19\n");

  auto solution = day13::Day13();

  // Assert
  EXPECT_EQ(solution.partOne(input), "295");
}

TEST(day_13, partTwo) {

  // Arrange
  std::istringstream input("939\n"
                           "1789,37,47,1889\n");

  auto solution = day13::Day13();

  // Assert
  EXPECT_EQ(solution.partTwo(input), "1202161486");
}

}