#include <istream>
#include <string>
#include <vector>
#include <stdexcept>
#include "read_file.hpp"
#include "solutions.hpp"
#include "map"

namespace day8 {

class Day8 : public solutions::Solution {
  public:
    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day8>();
    }

    std::string partOne(std::istream& input) override {
        auto str_input = utils::readStrInput(input);
        std::vector<std::pair<std::string, std::string>> commands;

        // do a bit of parsing
        for(auto s : str_input) {
            size_t pos;
            pos = s.find(" ");
            std::pair<std::string, std::string> command{ s.substr(0, pos), s.substr(pos+1, s.length() -1) };
            commands.push_back(command);
        }

        int accu = 0;
        int i=0;
        std::map<int, int> seen;

        while(i<commands.size()) {
            
            if(seen.count(i) == 0) {
                seen[i] = 1;
            } else {
                seen[i] = 2;
            }

            if(seen[i] > 1) {
                return std::to_string(accu);
            }

            if(commands[i].first == "nop") {
                i++;
            }
            else if(commands[i].first == "acc") {
                accu += std::stoi(commands[i].second);
                i++;
            }
                
            else if(commands[i].first == "jmp") {
                i+=std::stoi(commands[i].second);
            }
            else {
                throw std::runtime_error("unexpected op code :(");
            }
        }


    }

    std::string partTwo(std::istream& input) override {
        return "";
    }

};

} //namespace day8