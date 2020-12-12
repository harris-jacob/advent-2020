#include <istream>

#include "gtest/gtest.h"
#include "day_10.hpp"

namespace test{

TEST(day_10, partOne) {

      // Arrange
      std::istringstream input(
            "16\n"
            "10\n"
            "15\n"
            "5\n"
            "1\n"
            "11\n"
            "7\n"
            "19\n"
            "6\n"
            "12\n"
            "4\n"
  );

    auto solution = day10::Day10();

    // Assert
    EXPECT_EQ(solution.partOne(input), "35");
}


TEST(day_10, partTwo) {

      // Arrange
      std::istringstream input(
            "28\n"
            "33\n"
            "18\n"
            "42\n"
            "31\n"
            "14\n"
            "46\n"
            "20\n"
            "48\n"
            "47\n"
            "24\n"
            "23\n"
            "49\n"
            "45\n"
            "19\n"
            "38\n"
            "39\n"
            "11\n"
            "1\n"
            "32\n"
            "25\n"
            "35\n"
            "8\n"
            "17\n"
            "7\n"
            "9\n"
            "4\n"
            "2\n"
            "34\n"
            "10\n"
            "3\n"
  );

    auto solution = day10::Day10();

    // Assert
    EXPECT_EQ(solution.partTwo(input), "19208");
}


} // namespace test