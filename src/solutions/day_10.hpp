#include <string>
#include <istream>
#include <vector>
#include <algorithm>
#include <map>
#include "solutions.hpp"
#include "read_file.hpp"

namespace day10 {

class Day10: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day10>();
    }

    std::string partOne(std::istream& input) override {
        adapters = utils::readIntInput(input);

        // add zero 
        adapters.push_back(0);

        // sort input
        std::sort(adapters.begin(), adapters.end());
        int one_count=0;
        int three_count=0;


        adapters.push_back(adapters.back() + 3);

        for (int i=1; i<adapters.size(); i++) {

            // Prefer 1, if ! then two else use 3, otherwise it's impossible
            if(adapters[i] == adapters[i-1] + 1) {
                one_count ++;
            }

            else if(adapters[i] == adapters[i-1] + 3) {
                three_count++;
            } else {
                throw std::runtime_error("No matching jolt value");
            }

        }

        return std::to_string(one_count * three_count);

    }

    std::string partTwo(std::istream& input) override {
        adapters = utils::readIntInput(input);
        
        // add zero 
        adapters.push_back(0);

        // sort input
        std::sort(adapters.begin(), adapters.end());
        int one_count=0;
        int three_count=0;


        adapters.push_back(adapters.back() + 3);

        // solve by dynamic programming
        return std::to_string(eval_step(0));
    }

    long eval_step(int i) {
        // our ith + 1 step
        int j = i + 1;

        // we've reached the end
        if(i == adapters.size() - 1) {
            return 1;
        }

        // If we've alerady seen i save compute
        if(memoized_sum[i]) {
            return memoized_sum[i];
        }
        
        long count = 0;

        // as long as we don't exceed 3 diff we're good
        while(adapters[j] - adapters[i] <= 3 && j < adapters.size()) {
            count += eval_step(j);
            j++;
        }

        // add to our table
        memoized_sum[i] = count;
        return count;
    }

  private:
    std::map<int, long> memoized_sum;
    std::vector<int> adapters;
};

} // namespace day10