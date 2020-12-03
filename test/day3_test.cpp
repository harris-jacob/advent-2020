#include "read_file.hpp"
#include "gtest/gtest.h"
#include <vector>
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
    std::vector<std::string> input{
        "..##.......",
        "#...#...#..",
        ".#....#..#.",
        "..#.#...#.#",
        ".#...##..#.",
        "..#.##.....",
        ".#.#.#....#",
        ".#........#",
        "#.##...#...",
        "#...##....#",
        ".#..#...#.#"
    };

    // Act/Assert
    EXPECT_EQ(day3::partOne(input), 7);
}

TEST(day_3, partTwo) {
    // Arrange
    // Arrange
    std::ifstream infile("./input/day_3.txt");

    // Act
    std::vector<std::string> input = utils::readStrInput(infile);
    
    
    // Act/Assert
    EXPECT_EQ(day3::partTwo(input), 336);
}


} // namespace test
