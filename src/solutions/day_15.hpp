#include <string>
#include <vector>
#include <unordered_map>
#include "solutions.hpp"
#include "read_file.hpp"

namespace day15 {

class Day15: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day15>();
    }


    std::string partOne(std::istream& input) override {
        auto ints = parse(input);

        // map of seen to when it was seen
        std::unordered_map<int, int> seen{};

        // sort preamble
        // bit confusing because here i is previous turn
        for(int i=0; i<ints.size()-1; ++i) {
            seen[ints[i]] = i+1;
        }
        int previous = ints.back();

        // do rest
        for(int i=ints.size(); i<2020; ++i) {
            // not in input
            if(seen.count(previous) == 0) {
                seen[previous] = i;
                previous = 0;
            } else {
                int last_seen = seen[previous];
                int current = i - last_seen;
                seen[previous] = i;
                previous = current;
            }
        }

        return std::to_string(previous);

    }

    

    std::string partTwo(std::istream& input) override {
        auto ints = parse(input);

        // map of seen to when it was seen
        std::unordered_map<int, int> seen{};

        // sort preamble
        // bit confusing because here i is previous turn
        for(int i=0; i<ints.size()-1; ++i) {
            seen[ints[i]] = i+1;
        }
        int previous = ints.back();

        // do rest
        for(int i=ints.size(); i<30000000; ++i) {
            // not in input
            if(seen.count(previous) == 0) {
                seen[previous] = i;
                previous = 0;
            } else {
                int last_seen = seen[previous];
                int current = i - last_seen;
                seen[previous] = i;
                previous = current;
            }
        }

        return std::to_string(previous);

    }

  private:
    std::vector<int> parse(std::istream& input) {
        std::vector<int> v;
        std::string s;
        while(std::getline(input, s, ',')) {
            v.push_back(std::stoi(s));
        }
        return v;
    }
};

} //namespace day15