#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "solutions.hpp"
#include "read_file.hpp"

namespace day17 {

class Day17: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day17>();
    }

    std::string partOne(std::istream& input) override {
        for(int i=0; i<=5; i++) {
            read(input);
            step();
        }

        int sum = count();

        return std::to_string(sum);

    }

    std::string partTwo(std::istream& input) override {
        for(int i=0; i<= 5; i++) {
            read4D(input);
            step4D();
        }

        int sum = count4D();

        return std::to_string(sum);

    }

  private: 
    // X,Y,Z map
    std::map<int, std::map<int, std::map<int, bool>>> grid;
    std::map<int, std::map<int, std::map<int, std::map<int, bool>>>> grid4d;

    void read(std::istream& input) {
        auto initial_state = utils::readStrInput(input);

        for (int x = 0; x< initial_state.size(); x++) {
            for (int y=0; y<initial_state[x].size(); y++) {
                if(initial_state[x][y] == '#') {
                    grid[x][y][0] = true;
                } else {
                    grid[x][y][0] = false;
                }
            }
        }
    }

    //4D version
    void read4D(std::istream& input) {
        auto initial_state = utils::readStrInput(input);

        for (int x = 0; x< initial_state.size(); x++) {
            for (int y=0; y<initial_state[x].size(); y++) {
                if(initial_state[x][y] == '#') {
                    grid4d[x][y][0][0] = true;
                } else {
                    grid4d[x][y][0][0] = false;
                }
            }
        }
    }

    bool isActive(int x, int y, int z) {
        if(grid.find(x) == grid.end()) {
            return false;
        }

        if(grid[x].find(y) == grid[x].end()) {
            return false;
        }

        if(grid[x][y].find(z) == grid[x][y].end()) {
            return false;
        }

        if(grid[x][y][z]) {
            return true;
        }
     }

    bool isActive4D(int x, int y, int z, int w) {
        if(grid4d.find(x) == grid4d.end()) {
            return false;
        }

        if(grid4d[x].find(y) == grid4d[x].end()) {
            return false;
        }

        if(grid4d[x][y].find(z) == grid4d[x][y].end()) {
            return false;
        }

        if(grid4d[x][y][z].find(w) == grid4d[x][y][z].end()) {
            return false;
        }

        if(grid4d[x][y][z][w]) {
            return true;
        }
     }

    void step() {
        std::map<int, std::map<int, std::map<int, bool>>> newGrid = grid;
        for(int x = -14; x <= 14; x++) {
            for(int y = -14; y <= 14; y++ ) {
                for(int z = -7; z<=7; z++ ) {
                    int count = 0;
                    for(int dx = x-1; dx<= x+1; dx++) {
                        for(int dy = y-1; dy<= y+1; dy++) {
                            for(int dz = z-1; dz<= z+1; dz++) {
                                if(dz == z && dy == y && dx == x) {
                                    continue;
                                }
                                if(isActive(dx, dy, dz)) {
                                    count++;
                                }
                            }
                        }
                    }
                    if( grid[x][y][z] && (count == 2 || count == 3)) {
                    } else {
                        newGrid[x][y][z] = false;
                    }

                    if( !grid[x][y][z] && (count == 3)) {
                        newGrid[x][y][z] = true;
                    }
                }
            }
        }

        grid = newGrid;
    }

    // 4D version
    void step4D() {
        std::map<int, std::map<int, std::map<int, std::map<int, bool>>>> newGrid4d = grid4d;
        for(int x =-14; x <= 14; x++) {
            for(int y = -14; y <= 14; y++ ) {
                for(int z = -7; z<=7; z++ ) {
                    for(int w = -7; w<=7; w++) {
                        int count = 0;
                        for(int dx = x-1; dx<= x+1; dx++) {
                            for(int dy = y-1; dy<= y+1; dy++) {
                                for(int dz = z-1; dz<= z+1; dz++) {
                                    for(int dw = w-1; dw<= w+1; dw++) {
                                        if(dz == z && dy == y && dx == x && dw == w) {
                                        continue;
                                    }
                                        if(isActive4D(dx, dy, dz, dw)) {
                                            count++;
                                        }
                                    }
                                }
                            }
                        }

                        if( grid4d[x][y][z][w] && (count == 2 || count == 3)) {
                        } else {
                            newGrid4d[x][y][z][w] = false;
                        }

                        if( !grid4d[x][y][z][w] && (count == 3)) {
                            newGrid4d[x][y][z][w] = true;
                        }
                    }
                }
            }
        }

        grid4d = newGrid4d;
    }

    int count() {
        int sum=0;

        for(int x = -14; x <= 14; x++) {
            for(int y = -14; y<=14; y++) {            
                for(int z=-7; z<=7; z++) {
                    if(isActive(x, y, z)) {
                        sum++;
                    }
                }
            }
        }
        return sum;
    }

    // 4D version
    int count4D() {
        int sum=0;

        for(int x = -14; x <= 14; x++) {
            for(int y = -14; y<=14; y++) {
                for(int z=-7; z<=7; z++) {                    
                    for(int w = -7; w<=7; w++) {
                        if(isActive4D(x, y, z, w)) {
                            sum++;
                        }
                    }
                }
            }
        }
        return sum;
    }

};

} // namespace day16