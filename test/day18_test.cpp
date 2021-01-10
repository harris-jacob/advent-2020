#include <istream>

#include "day_18.hpp"
#include "gtest/gtest.h"

namespace test {

TEST(day_18, partOne) {

  // Arrange
  std::istringstream input(
      "1 + (2 * 3) + (4 * (5 + 6))"
  );

  auto solution = day18::Day18();

  // assert
  EXPECT_EQ(solution.partOne(input), "51");

}

} // namespace test