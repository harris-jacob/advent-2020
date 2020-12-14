#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <sstream>
#include "solutions.hpp"
#include "read_file.hpp"

namespace day13 {

class Day13: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day13>();
    }

    std::vector<int> parseBuses(std::string& input) {
        std::stringstream stream(input);
        std::string item{};
        std::vector<int> split;
        while(std::getline(stream, item, ',')) {
            if(item != "x")
                split.push_back(std::stoi(item));
        }

        return split;
    }

    std::string partOne(std::istream& input) override {
        auto instructions = utils::readStrInput(input);
        auto time = std::stoi(instructions[0]);
        std::vector<int> buses = parseBuses(instructions[1]);


        std::pair<int, int> best = {0, std::numeric_limits<int>::max()};
        for (auto bus : buses) {
            int time_cpy = time;
            while(true) {
                if(time_cpy % bus == 0) {
                    if(time_cpy < best.second) {
                        best.second = time_cpy;
                        best.first = bus;
                    }
                    break;
                }
                time_cpy++;
            }
        }

        return std::to_string((best.second - time) * best.first); 
    }

     std::string partTwo(std::istream& input) override {}
};

} //namespace day13