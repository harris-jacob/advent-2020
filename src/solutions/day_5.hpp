#pragma once
#include <memory>
#include <string>
#include <istream>
#include <math.h>
#include <algorithm>
#include "solutions.hpp"
#include "read_file.hpp"


namespace day5 {

class Day5 : public solutions::Solution {
  public:
    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day5>();
    }

    std::string partOne(std::istream& input) override {
        int max_seat=0;

        auto passes = utils::readStrInput(input);

        for (const std::string& pass : passes) {
            int row=0;
            int column=0;

            // handle rows
            for(int i=0; i< 7; ++i) {
                row += pass.at(i) == 'B' ? pow(2, 6-i) : 0;
            }

            // handle columns
            for(int i=6; i< 10; ++i) {
                column += pass.at(i) == 'R' ? pow(2, 9-i) : 0;
            }

            int seat = row * 8 + column;
            if (seat > max_seat) {
                max_seat = seat;
            }
        }

        return std::to_string(max_seat);
    }


    std::string partTwo(std::istream& input) override {
        std::vector<int> seats;
        auto passes = utils::readStrInput(input);

        for (const std::string& pass : passes) {
            int row=0;
            int column=0;

            // handle rows
            for(int i=0; i< 7; ++i) {
                row += pass.at(i) == 'B' ? pow(2, 6-i) : 0;
            }

            // handle columns
            for(int i=6; i< 10; ++i) {
                column += pass.at(i) == 'R' ? pow(2, 9-i) : 0;
            }

            int seat = row * 8 + column;
            seats.push_back(seat);
        }

        // sort our input
        std::sort(seats.begin(), seats.end());
        
        // loop through
        for(int i=0; i< seats.size() - 1; ++i) {
            if(seats[i] - seats[i + 1] == -2) {
                return std::to_string(seats[i]+1);
            }
        }

        return std::to_string(-1);
    }
};

} // namespace day5