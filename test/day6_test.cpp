#include "read_file.hpp"
#include "gtest/gtest.h"
#include "day_6.hpp"
#include <fstream>

namespace test{

TEST(day_6, partOne) {

 // Arrange
  std::istringstream input(
    "abc\n\n"
    "a\n"
    "b\n"
    "c\n\n"
    "ab\n"
    "ac\n\n"
    "a\n"
    "a\n"
    "a\n"
    "a\n\n"
    "b"
  );
    auto solution = day6::Day6();

    //Assert
    EXPECT_EQ(solution.partOne(input), "11");
}

TEST(day_6, partTwo) {

 // Arrange
  std::istringstream input(
    "abc\n\n"
    "a\n"
    "b\n"
    "c\n\n"
    "ab\n"
    "ac\n\n"
    "a\n"
    "a\n"
    "a\n"
    "a\n\n"
    "b"
  );
    auto solution = day6::Day6();

    //Assert
    EXPECT_EQ(solution.partTwo(input), "6");
}



} // namepsace test