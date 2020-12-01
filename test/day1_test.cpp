#include "day_1.hpp"
#include "gtest/gtest.h"
#include <vector>

namespace test {

TEST(day_1, partOne) {
  // Arrange
  std::vector<int> input{1721, 979, 366, 299, 675, 1456};

  // Assert
  EXPECT_EQ(day1::partOne(input), 514579);
}

} // namespace test
