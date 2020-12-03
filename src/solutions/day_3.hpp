#pragma one 

#include <vector>
#include <string>

namespace day3{

int partOne(std::vector<std::string> input) {
    int count=0; // how many trees have we hit.
    int pointer=0; // where are we in the array
    for(int i=0; i< input.size(); ++i) {
            if(input[i][pointer] == '#') {
                count++;
            }
            // if we reach the end the pattern repeats.
            if(pointer < input[i].size()-3) {
                pointer+=3;

            } else {
                int remainder = input[i].size() - pointer;
                pointer= (3 - remainder);
            }
    }
    return count;
}

} // namespace day3