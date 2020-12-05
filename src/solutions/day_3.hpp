#pragma one 

#include <algorithm>
#include <vector>
#include <string>
#include "read_file.hpp"
#include "solutions.hpp"

namespace day3{

class Day3 : public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day3>();
        }


    // return count of trees for a given slope
    int assessSlope(std::vector<std::string> input, int width_step, int height_step) {
        int count=0; // how many trees have we hit.
        int pointer=0; // where are we in the array

        for(int i=0; i< input.size(); i+=height_step) {
                if(input[i][pointer] == '#') {
                    count++;
                }
                // if we reach the end the pattern repeats.
                if(pointer < input[i].size()-width_step) {
                    pointer+=width_step;

                } else {
                    int remainder = input[i].size() - pointer;
                    pointer= (width_step - remainder);
                }
        }

        return count;
    }

    std::string partOne(std::istream& input) {

        auto map = utils::readStrInput(input);

        return std::to_string(assessSlope(map, 3, 1));
    }

    std::string partTwo(std::istream& input) {
        auto map = utils::readStrInput(input);
        
        long a = assessSlope(map, 1, 1);
        long b = assessSlope(map, 3, 1);
        long c = assessSlope(map, 5, 1);
        long d = assessSlope(map, 7, 1);
        long e = assessSlope(map, 1, 2);
        return std::to_string(a*b*c*d*e);
    }
};

} // namespace day3