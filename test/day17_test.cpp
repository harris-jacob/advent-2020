#include <istream>

#include "day_17.hpp"
#include "gtest/gtest.h"

namespace test {

TEST(day_17, partOne) {

  // Arrange
  std::istringstream input(
    ".#.\n"
    "..#\n"
    "###\n"
  );

  auto solution = day17::Day17();

  // assert
  EXPECT_EQ(solution.partOne(input), "112");

}

} // namespace test
