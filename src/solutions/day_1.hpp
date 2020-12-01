#pragma once

#include <vector>
#include <unordered_set>

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

int partTwo(std::vector<int> input) {
  
  // construct set
  std::unordered_set<int> int_set;
  for(int i = 0; i < input.size(); i++) {
    int_set.insert(input[i]);
  }

  for(int i = 0; i<input.size(); i++) {
    for(int j = i +1; j < input.size(); j++) {
      int required = 2020 - input[i] - input[j];
      auto val = int_set.find(required);
      if(val != int_set.end()) {
        return *val * input[i] * input[j];
      }
    }
  }

  return -1;
}

} // namespace day1