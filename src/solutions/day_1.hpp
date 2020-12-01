#pragma once

#include <vector>

namespace day1 {

int partOne(std::vector<int> input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = i + 1; j < input.size(); j++) {
      if (input[i] + input[j] == 2020) {
        return input[i] * input[j];
      }
    }
  }
  return -1;
}

} // namespace day1