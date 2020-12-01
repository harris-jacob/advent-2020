#pragma once

#include <vector>
#include <unordered_map>

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
  
  // construct map
  std::unordered_map<int, int> int_map;
  for(int i = 0; i < input.size(); i++) {
    int_map[input[i]] = i;
  }

  for(int i = 0; i<input.size(); i++) {
    for(int j = i +1; j < input.size(); j++) {
      int required = 2020 - input[i] - input[j];
      auto val = int_map.find(required);
      if(val != int_map.end()) {
        return val->first * input[i] * input[j];
      }
    }
  }

  return -1;
}

} // namespace day1