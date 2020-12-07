#include <memory>
#include <string>
#include <istream>
#include <set>
#include <map>
#include "solutions.hpp"
#include "read_file.hpp"


namespace day6 {

class Day6 : public solutions::Solution {
  public:
    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day6>();
    }

    std::string partOne(std::istream& input) override {
        std::vector<std::set<char>> groups{};
        std::string line;
        std::set<char> group;
        int sum=0;

        while(std::getline(input, line)) {

            if(line.empty()) {
                groups.push_back(group);
                group.clear();
            }

            for(char letter : line) {
                if(group.count(letter) == 0) {
                    group.insert(letter);
                }
            }
        }

        // last element has no newline
        for(char letter : line) {
            if(group.count(letter) == 0) {
                group.insert(letter);
            }
        }
        groups.push_back(group);

        // Cuont the length of sets
        for(std::set<char>& set : groups) {
            sum+=set.size();
        }

        return std::to_string(sum);
    }

    std::string partTwo(std::istream& input) override {
        int group_size = 0;
        std::string line;
        std::map<char, int> group;
        int sum=0;

        while(std::getline(input, line)) {
            if(line.empty()) {
                for(auto const& val : group) {
                    if(group[val.first] == group_size) {
                        sum ++;
                    }
                }
                group.clear();
                group_size = 0;
            } else {
                group_size++;
            }

            // add letters to the set
            for(char letter : line) {
                    if(group.count(letter) == 0) {
                        group[letter] = 1;
                    } else {
                        group[letter]++;
                    }
                }
        }


        for(auto const& val : group) {
            if(group[val.first] == group_size) {
                sum ++;
            }
        }

        return std::to_string(sum);
    }

};

} //namespace day6