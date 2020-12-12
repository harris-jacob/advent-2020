#include <string>
#include <istream>
#include <vector>
#include <set>
#include "solutions.hpp"
#include "read_file.hpp"


namespace day9 {

class Day9 : public solutions::Solution {
  public:
    Day9() :  preamble_length(25) {} 
    Day9(int preamble) : preamble_length(preamble){}

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day9>();
    }

    std::string partOne(std::istream& input) override {
        ints = utils::readLongInput(input);
        auto index = findFirstNonSum(ints);
        return std::to_string(ints[index]);
    }
    
    std::string partTwo(std::istream& input) override {
        ints = utils::readLongInput(input);
        auto index = findFirstNonSum(ints);

        // loop through until matching index
        for(int i=0; i< index; ++i) {
            long sum = 0;
            for(int j=i; j< index; ++j) {
                sum+=ints[j];
                if(sum == ints[index]) {
                    //return min and max
                    auto min = std::min_element(ints.begin() + i, ints.begin() + j);
                    auto max = std::max_element(ints.begin() + i, ints.begin() + j);
                    return std::to_string(*min + *max);
                }
                else if(sum > ints[index]) {
                    break;
                }
            }
        }
    }


  private:
    int preamble_length;
    std::vector<long> ints;

    int findFirstNonSum(std::vector<long> ints) {
        std::set<int> sum_buffer;
        // handle preamble
        for(int i=0; i<preamble_length; ++i) {
            sum_buffer.insert(ints[i]);
        }

        // loop through ints
        for(int i=preamble_length; i<ints.size(); ++i) {
            // check the set for a match
            if(!checkSet(sum_buffer, ints[i])) {
                return i;
            }

            // remove the oldest element
            sum_buffer.erase(ints[i-preamble_length]);
            sum_buffer.insert(ints[i]);
        }
    }

    bool checkSet(std::set<int> sum_buffer, int sum) {
        for (int num : sum_buffer ) {
            int target = sum - num;
            if(sum_buffer.find(target) != sum_buffer.end()) {
                return true;
            }
        }
        return false;
    }

};

} // namespace day 9