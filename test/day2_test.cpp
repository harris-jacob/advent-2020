#include "read_file.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <string>

namespace test {


TEST(day_2, loadInput) {
  std::ifstream infile("../../input/day_2.txt");
  std::vector<std::string> input = utils::readStrInput(infile);
  EXPECT_EQ(input[0], "5-9 g: ggccggmgn");
}


} // namespace test
