#include <istream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include "read_file.hpp"
#include "solutions.hpp"

namespace day8 {

class Day8 : public solutions::Solution {
  public:
    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day8>();
    }

    int evaluateOperation(int i, std::pair<std::string, std::string> command) {

        if(command.first == "nop") {
            i++;
        }
        else if(command.first == "acc") {
            accu += std::stoi(command.second);
            i++;
        }
            
        else if(command.first == "jmp") {
            i+=std::stoi(command.second);
        }
        else {
            throw std::runtime_error("unexpected op code :(");
        }

        return i;
    }

    std::vector<std::pair<std::string, std::string>> parse(std::istream& input) {
        auto str_input = utils::readStrInput(input);
        std::vector<std::pair<std::string, std::string>> commands;

        // do a bit of parsing
        for(auto s : str_input) {
            size_t pos;
            pos = s.find(" ");
            std::pair<std::string, std::string> command{ s.substr(0, pos), s.substr(pos+1, s.length() -1) };
            commands.push_back(command);
        }

        return commands;

    }

    std::string partOne(std::istream& input) override {
        accu = 0;
        int i=0;
        std::map<int, int> seen;
        auto commands = parse(input);
        while(i < commands.size()) {
            if(seen.count(i) == 0) {
                seen[i] = 1;
            } else {
                seen[i] = 2;
            }

            if(seen[i] > 1) {
                return std::to_string(accu);
            }
            i = evaluateOperation(i, commands[i]);
        }
    }

    std::string partTwo(std::istream& input) override {
        auto commands = parse(input);
        int i=0;
        while(i<commands.size()) {
            if(commands[i].first == "jmp") {
                commands[i].first = "nop";
                auto ans = eval(commands);
                if(ans == -1) {
                    commands[i].first = "jmp";
                } else {
                    return std::to_string(ans);
                }
            } else if(commands[i].first == "nop") {
                commands[i].first = "jmp";
                auto ans = eval(commands);
                if(ans == -1) {
                    commands[i].first = "nop";
                } else {
                    return std::to_string(ans);
                }
            }
            i++;
        }
        return "-1";
    }

    int eval(std::vector<std::pair<std::string, std::string>>& commands){
        accu=0;
        int i=0;
        std::map<int, int> seen;
        while(i < commands.size()) {
            if(seen.count(i) == 0) {
                seen[i] = 1;
            } else {
                seen[i] = 2;
            }

            if(seen[i] > 1) {
                return -1;
            }
            i = evaluateOperation(i, commands[i]);
        }
        return accu;
    }

  private:
    int accu = 0;

};

} //namespace day8