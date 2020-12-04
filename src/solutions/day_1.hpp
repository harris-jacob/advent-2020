#pragma once

#include "solutions.hpp"
#include "read_file.hpp"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

namespace day1 {

class Day1 : public solutions::Solution {
  public:
    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day1>();
    }

    // Solve part one
    int partOne(std::istream& input) override {
      // read input
      auto ints = utils::readIntInput(input);

      for (int i = 0; i < ints.size(); i++) {
        for (int j = i + 1; j < ints.size(); j++) {
          if (ints[i] + ints[j] == 2020) {
            return ints[i] * ints[j];
          }
        }
      }
      return -1;
    }

    // Solve part two
    int partTwo(std::istream& input) override {
      // read input
      auto ints = utils::readIntInput(input);

      // construct set
      std::unordered_set<int> int_set;
      for(int i = 0; i < ints.size(); i++) {
        int_set.insert(ints[i]);
      }

      for(int i = 0; i<ints.size(); i++) {
        for(int j = i +1; j < ints.size(); j++) {
          int required = 2020 - ints[i] - ints[j];
          auto val = int_set.find(required);
          if(val != int_set.end()) {
            return *val * ints[i] * ints[j];
          }
        }
      }
      return -1;
    }
};

} // namespace day1