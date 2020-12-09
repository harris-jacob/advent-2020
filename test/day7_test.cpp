#include <sstream>
#include "day_7.hpp"
#include "gtest/gtest.h"


namespace test{

TEST(day_7, partOne) {

 // Arrange
  std::istringstream input(
        "light red bags contain 1 bright white bag, 2 muted yellow bags.\n"
        "dark orange bags contain 3 bright white bags, 4 muted yellow bags.\n"
        "bright white bags contain 1 shiny gold bag.\n"
        "muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.\n"
        "shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.\n"
        "dark olive bags contain 3 faded blue bags, 4 dotted black bags.\n"
        "vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.\n"
        "faded blue bags contain no other bags.\n"
        "dotted black bags contain no other bags.\n"
  );

    auto solution = day7::Day7();

    // Assert
    EXPECT_EQ(solution.partOne(input), "4");
}

TEST(day_7, partTwo) {

 // Arrange
  std::istringstream input(
            "shiny gold bags contain 2 dark red bags.\n"
            "dark red bags contain 2 dark orange bags.\n"
            "dark orange bags contain 2 dark yellow bags.\n"
            "dark yellow bags contain 2 dark green bags.\n"
            "dark green bags contain 2 dark blue bags.\n"
            "dark blue bags contain 2 dark violet bags.\n"
            "dark violet bags contain no other bags.\n"
  );

    auto solution = day7::Day7();

    // Assert
    EXPECT_EQ(solution.partTwo(input), "126");
}

} // namespace test