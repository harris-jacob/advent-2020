#include "read_file.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <fstream>
#include <string>
#include "day_3.hpp"

namespace test {


TEST(day_3, loadInput) {

  // Arrange
  std::ifstream infile("./input/day_3.txt");

  // Act
  std::vector<std::string> input = utils::readStrInput(infile);

  // Assert
  EXPECT_EQ(input[0], "...............#...#..#...#....");
}

TEST(day_3, partOne) {
  // Arrange
  std::istringstream input(
        "..##.......\n"
        "#...#...#..\n"
        ".#....#..#.\n"
        "..#.#...#.#\n"
        ".#...##..#.\n"
        "..#.##.....\n"
        ".#.#.#....#\n"
        ".#........#\n"
        "#.##...#...\n"
        "#...##....#\n"
        ".#..#...#.#\n"
  );

    auto solution = day3::Day3();

    // Act/Assert
    EXPECT_EQ(solution.partOne(input), "7");
}

TEST(day_3, partTwo) {
  // Arrange
  std::istringstream input(
        "..##.......\n"
        "#...#...#..\n"
        ".#....#..#.\n"
        "..#.#...#.#\n"
        ".#...##..#.\n"
        "..#.##.....\n"
        ".#.#.#....#\n"
        ".#........#\n"
        "#.##...#...\n"
        "#...##....#\n"
        ".#..#...#.#\n"
  );

    auto solution = day3::Day3();

    
    
    // Act/Assert
    EXPECT_EQ(solution.partTwo(input), "336");
}


} // namespace test
