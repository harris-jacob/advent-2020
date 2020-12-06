#include "read_file.hpp"
#include "gtest/gtest.h"
#include "day_5.hpp"
#include <fstream>

namespace test{

TEST(day_5, loadInput) {

    // Arrange
    std::ifstream infile("./input/day_5.txt");

    //Act
    auto input = utils::readStrInput(infile);

    //Assert
    EXPECT_EQ(input[0], "BBFBBBFLRR");
}

TEST(day_5, partOne) {
      // Arrange
  std::istringstream input(
      "FBFBBFFRLR\n"
      "BFFFBBFRRR\n"
      "FFFBBBFRRR\n"
      "BBFFBBFRLL\n"
  );

    auto solution = day5::Day5();

    //Assert
    EXPECT_EQ(solution.partOne(input), "820");
}

} // namepsace test