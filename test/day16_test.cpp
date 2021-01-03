#include <istream>

#include "day_16.hpp"
#include "gtest/gtest.h"

namespace test {

TEST(day_16, partOne) {

  // Arrange
  std::istringstream input(
    "class: 1-3 or 5-7\n"
    "row: 6-11 or 33-44\n"
    "seat: 13-40 or 45-50\n\n"

    "your ticket:\n"
    "7,1,14\n\n"

    "nearby tickets:\n"
    "7,3,47\n"
    "40,4,50\n"
    "55,2,20\n"
    "38,6,12\n"
  );

  auto solution = day16::Day16();

  // Assert
  EXPECT_EQ(solution.partOne(input), "71");
}

} // namespace test
