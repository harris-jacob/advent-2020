#include <istream>

#include "gtest/gtest.h"
#include "day_9.hpp"

namespace test{

TEST(day_9, partOne) {

      // Arrange
      std::istringstream input(
            "35\n"
            "20\n"
            "15\n"
            "25\n"
            "47\n"
            "40\n"
            "62\n"
            "55\n"
            "65\n"
            "95\n"
            "102\n"
            "117\n"
            "150\n"
            "182\n"
            "127\n"
            "219\n"
            "299\n"
            "277\n"
            "309\n"
            "576\n"
  );

    auto solution = day9::Day9(5);

    // Assert
    EXPECT_EQ(solution.partOne(input), "127");
}

TEST(day_9, partTwo) {

      // Arrange
      std::istringstream input(
            "35\n"
            "20\n"
            "15\n"
            "25\n"
            "47\n"
            "40\n"
            "62\n"
            "55\n"
            "65\n"
            "95\n"
            "102\n"
            "117\n"
            "150\n"
            "182\n"
            "127\n"
            "219\n"
            "299\n"
            "277\n"
            "309\n"
            "576\n"
  );

    auto solution = day9::Day9(5);

    // Assert
    EXPECT_EQ(solution.partTwo(input), "62");
}



} // namespace test