#include "read_file.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "day_2.hpp"

namespace test {


TEST(day_2, loadInput) {

  // Arrange
  std::ifstream infile("./input/day_2.txt");

  // Act
  std::vector<std::string> input = utils::readStrInput(infile);

  // Assert
  EXPECT_EQ(input[0], "5-9 g: ggccggmgn");
}

TEST(day_2, getPassword) {
  // Arrange
  std::string test_password = "1-3 a: abcde";

  //Act
  auto password = day2::createPassword(test_password);

  EXPECT_EQ(password.max, 3);
  EXPECT_EQ(password.min, 1);
  EXPECT_EQ(password.target, 'a');
  EXPECT_EQ(password.password, "abcde");
}

TEST(day_2, partOne) {
  // Arrange
  std::istringstream input(
    "1-3 a: abcde\n"
    "1-3 b: cdefg\n"
    "2-9 c: ccccccccc\n"
  );

  auto solution = day2::Day2();

  // Act/Assert
  EXPECT_EQ(solution.partOne(input), "2");

}

TEST(day_2, partTwo) {
  // Arrange
  std::istringstream input(
    "1-3 a: abcde\n"
    "1-3 b: cdefg\n"
    "2-9 c: ccccccccc\n"
  );

  auto solution = day2::Day2();

  // Act/Assert
  EXPECT_EQ(solution.partTwo(input), "1");

}

} // namespace test
