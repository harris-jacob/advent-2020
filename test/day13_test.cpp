#include <istream>

#include "gtest/gtest.h"
#include "day_13.hpp"

TEST(day_13, partOne) {

      // Arrange
      std::istringstream input(
          "939\n"
          "7,13,x,x,59,x,31,19\n"
  );

    auto solution = day13::Day13();

    // Assert
    EXPECT_EQ(solution.partOne(input), "295");
}