#include <sstream>
#include "day_8.hpp"
#include "gtest/gtest.h"


namespace test{

TEST(day_8, partOne) {

      // Arrange
      std::istringstream input(
        "nop +0\n"
        "acc +1\n"
        "jmp +4\n"
        "acc +3\n"
        "jmp -3\n"
        "acc -99\n"
        "acc +1\n"
        "jmp -4\n"
        "acc +6\n"
  );

    auto solution = day8::Day8();

    // Assert
    EXPECT_EQ(solution.partOne(input), "5");
}


} // namespace test