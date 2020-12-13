#include <istream>

#include "gtest/gtest.h"
#include "day_11.hpp"

TEST(day_11, partOne) {

      // Arrange
      std::istringstream input(
            "L.LL.LL.LL\n"
            "LLLLLLL.LL\n"
            "L.L.L..L..\n"
            "LLLL.LL.LL\n"
            "L.LL.LL.LL\n"
            "L.LLLLL.LL\n"
            "..L.L.....\n"
            "LLLLLLLLLL\n"
            "L.LLLLLL.L\n"
            "L.LLLLL.LL\n"
  );

    auto solution = day11::Day11();

    // Assert
    EXPECT_EQ(solution.partOne(input), "37");
}

TEST(day_11, partTwo) {

      // Arrange
      std::istringstream input(
            "L.LL.LL.LL\n"
            "LLLLLLL.LL\n"
            "L.L.L..L..\n"
            "LLLL.LL.LL\n"
            "L.LL.LL.LL\n"
            "L.LLLLL.LL\n"
            "..L.L.....\n"
            "LLLLLLLLLL\n"
            "L.LLLLLL.L\n"
            "L.LLLLL.LL\n"
  );

    auto solution = day11::Day11();

    // Assert
    EXPECT_EQ(solution.partTwo(input), "26");
}