#pragma one 

#include <algorithm>
#include <vector>
#include <string>

namespace day3{

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

int partOne(std::vector<std::string> input) {
    return assessSlope(input, 3, 1);
}

long partTwo(std::vector<std::string> input) {
    long a = assessSlope(input, 1, 1);
    long b = assessSlope(input, 3, 1);
    long c = assessSlope(input, 5, 1);
    long d = assessSlope(input, 7, 1);
    long e = assessSlope(input, 1, 2);
    return a*b*c*d*e;
}

} // namespace day3