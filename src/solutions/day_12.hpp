#pragma once
#include <string>
#include <vector>
#include <cstdlib>

#include "solutions.hpp"
#include "read_file.hpp"

namespace day12 {

class Day12: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day12>();
    }

    std::string partOne(std::istream& input) override {
        instructions = utils::readStrInput(input);
        int lat = 0;
        int lon = 0;
        int dir = 1;
        std::vector<std::string> dirs{"N", "E", "S", "W"};
        for (auto instruction : instructions) {
            int val = std::stoi(instruction.substr(1, instruction.back()));
            if(instruction[0] == 'N' || (instruction[0] == 'F' && dir == 0)) {
                lat += val;
            }
            else if(instruction[0] == 'E' || (instruction[0] == 'F' && dir == 1)) {
                lon += val;
            }
            else if(instruction[0] == 'S' || (instruction[0] == 'F' && dir == 2)) {
                lat -= val;
            }
            else if(instruction[0] == 'W' || (instruction[0] == 'F' && dir == 3)) {
                lon -= val;
            }

            else if(instruction[0] == 'R') {
                dir = (dir + val / 90) % 4;
            }

            else if(instruction[0] == 'L') {
                dir = (dir + 3*val / 90) % 4;
            }
        }

        return std::to_string(std::abs(lon) + std::abs(lat));
    }

    std::string partTwo(std::istream& input) override {
        instructions = utils::readStrInput(input);
        int lat = 0;
        int lon = 0;
        std::vector<std::string> dirs{"N", "E", "S", "W"};
        for (auto instruction : instructions) {
            int val = std::stoi(instruction.substr(1, instruction.back()));
            if(instruction[0] == 'N') {
                waypoint.first += val;
            }
            else if(instruction[0] == 'E') {
                waypoint.second += val;
            }
            else if(instruction[0] == 'S') {
                waypoint.first -= val;
            }
            else if(instruction[0] == 'W') {
                waypoint.second -= val;
            }

            else if(instruction[0] == 'R') {
                while(val > 0) {
                    // yeah I had no clue how to do rotation
                    int first = -waypoint.second;
                    int second = waypoint.first;
                    waypoint.first = first;
                    waypoint.second = second;
                    val-=90;
                }
            }
            else if(instruction[0] == 'L') {
                while(val > 0) {
                    int first = waypoint.second;
                    int second = -waypoint.first;
                    waypoint.first = first;
                    waypoint.second = second;
                    val-=90;
                }
            }
            else if(instruction[0] == 'F') {
                lat+= waypoint.first*val;
                lon+=waypoint.second*val;
            }
        }

        return std::to_string(std::abs(lon) + std::abs(lat));

    }

  private:
    std::vector<std::string> instructions;
    std::pair<int, int> waypoint{1, 10};
};

} // namespace day12