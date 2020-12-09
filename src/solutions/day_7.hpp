#pragma once
#include <istream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "solutions.hpp"
#include "read_file.hpp"

namespace day7 {

struct Bag {
    std::string name;
    int count;
};

// TODO - should really include the map as a member of the class.
class Day7 : public solutions::Solution {
  public:
    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day7>();
    }

    std::map<std::string, std::vector<Bag>> parse(std::istream& input) {
        // map of bags
        std::map<std::string, std::vector<Bag>> bags{};

        // preprocessing
        std::vector<std::string> string_input = utils::readStrInput(input);
        for (std::string s : string_input) {
            std::vector<Bag> children;
            std::string lhs = s.substr(0, s.find(" bags contain"));
            std::string rhs = s.substr(s.find(lhs) + lhs.length() + 14);
            
            // for bags that contain nothing
            if(s.find("contain no other bags") != std::string::npos) {
                continue;
            }

            // deal with bags
            std::string token;
            size_t pos = 0;
            while((pos = rhs.find(",")) != std::string::npos) {
                token = rhs.substr(0, pos);
                
                // make a bag
                Bag bag;
                bag.count = (int) token[0] - 48;
                bag.name = token.substr(2, token.find("bag") - 3);
                children.push_back(bag);

                rhs.erase(0, pos + 2);
                

            }

            // deal with last
            Bag bag;
            bag.count = (int) rhs[0] - 48;
            bag.name = rhs.substr(2, rhs.find("bag") -3);
            children.push_back(bag);

            // add to the map
            if(bags.count(lhs) == 0) {
                bags[lhs] = children;
            }
        }

        return bags;
    }

    std::string partOne(std::istream& input) override {
        int count = 0;
        auto bags = parse(input);

        for(auto const& x : bags) {
            if(search_bags(bags, x.first, "shiny gold")) {
                count ++;
            }
        }

        return std::to_string(count);

    }
    // recursively search bags for required bag
    bool search_bags(std::map<std::string, std::vector<Bag>> &bags, std::string start_key, std::string required) {
        for(auto bag : bags[start_key]) {
            if(bag.name == required) {
                return true;
            }
            if(search_bags(bags, bag.name, required)) {
                return true;
            };
        }

        return false;
    }

    int count_bags(std::map<std::string, std::vector<Bag>> &bags, std::string start_key, int number, int count) {
        if(bags[start_key].size() == 0) {
            return count;
        }

        for(auto bag : bags[start_key]) {
            count += number*bag.count;
            count = count_bags(bags, bag.name, bag.count * number , count);


        }

        return count;
    }

    std::string partTwo(std::istream& input) override {
        auto bags = parse(input);
        int count = count_bags(bags, "shiny gold", 1, 0);
        return std::to_string(count);
    }

};

} // namespace day7