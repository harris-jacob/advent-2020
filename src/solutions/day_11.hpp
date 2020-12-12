#include <string>
#include <vector>

#include "solutions.hpp"
#include "read_file.hpp"


namespace day11 {

class Day11: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day11>();
    }

    std::string partOne(std::istream& input) override {
        grid = utils::readStrInput(input);

    while(true) {
            bool change = false;
            // copy the vector to new
            std::vector<std::string> newGrid;
            std::copy(grid.begin(), grid.end(), std::back_inserter(newGrid));
            int occupied = 0;
            for(int i=0; i< grid.size(); ++i) {
                for(int j=0; j<grid[i].length(); ++j) {

                    if(grid[i][j] == 'L') {
                        if(evalEmpty(i, j, newGrid)) {
                            change = true;
                        };
                    }

                    if(grid[i][j] == '#') {
                        if(evalOccupied(i, j, newGrid)) {
                            change = true;
                        }
                        occupied++;
                    }
                }
            }
            grid.clear();
            std::copy(newGrid.begin(), newGrid.end(), std::back_inserter(grid));

            if(!change) {
                return std::to_string(occupied);
            }
        }

    }

    std::string partTwo(std::istream& input) override {
        grid = utils::readStrInput(input);
            while(true) {
            bool change = false;
            // copy the vector to new
            std::vector<std::string> newGrid;
            std::copy(grid.begin(), grid.end(), std::back_inserter(newGrid));
            int occupied = 0;
            for(int i=0; i< grid.size(); ++i) {
                for(int j=0; j<grid[i].length(); ++j) {

                    if(grid[i][j] == 'L') {
                        if(evalEmptyP2(i, j, newGrid)) {
                            change = true;
                        };
                    }

                    if(grid[i][j] == '#') {
                        if(evalOccupiedP2(i, j, newGrid)) {
                            change = true;
                        }
                        occupied++;
                    }
                }
            }
            grid.clear();
            std::copy(newGrid.begin(), newGrid.end(), std::back_inserter(grid));

            if(!change) {
                return std::to_string(occupied);
            }
        }

    }

    bool evalEmpty(int row, int col, std::vector<std::string>& newGrid) {
        // by default change
        bool change = true;
        // find adjacents
        for(int i=-1; i <= 1; ++i) {
            int dr = row+i;
            for(int j=-1; j <= 1; ++j) {
                int dc = col+j;
                if(i == 0 && j == 0) {
                    continue;
                }
                // in bounds
                 if(dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[dr].length()) {
                     // if occupied false
                     change = grid[dr][dc] == '#' ? false : change;
                 }
            }
        }

        newGrid[row][col] = change ? '#' : newGrid[row][col];

        return change;

    }

    bool evalOccupied(int row, int col, std::vector<std::string>& newGrid) {

        int count = 0;
        // find adjacents
        for(int i=-1; i <= 1; ++i) {
            int dr = row+i;
            for(int j=-1; j <= 1; ++j) {
                int dc = col+j;
                if(i == 0 && j == 0) {
                    continue;
                }
                // in bounds
                 if(dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[dr].length()) {
                     if(grid[dr][dc] == '#') {
                         count++;
                     }
                 }
            }
        }

        newGrid[row][col] = count >= 4 ? 'L' : grid[row][col];

        return count >= 4;
    }

    // lazy modification for p2
    bool evalEmptyP2(int row, int col, std::vector<std::string>& newGrid) {

        bool change = true;
        // find adjacents
        for(int i=-1; i <= 1; ++i) {
            for(int j=-1; j <= 1; ++j) {
                int dr = row+i;
                int dc = col+j;
                if(i == 0 && j == 0) {
                    continue;
                }
                // in bounds
                 while(dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[dr].length() && grid[dr][dc] == '.') {
                     dr += i;
                     dc += j;
                 }

                // in bounds
                if(dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[dr].length() && grid[dr][dc] && grid[dr][dc] == '#') {
                    // if occupied false
                    change = false;
                }
            }
        }

        newGrid[row][col] = change ? '#' : newGrid[row][col];

        return change;

    }

    // lazy modification for P2
    bool evalOccupiedP2(int row, int col, std::vector<std::string>& newGrid) {

        int count = 0;
        // find adjacents
        for(int i=-1; i <= 1; ++i) {
            for(int j=-1; j <= 1; ++j) {
                int dr = row+i;
                int dc = col+j;
                if(i == 0 && j == 0) {
                    continue;
                }
                // in bounds

                 while(dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[dr].length() && grid[dr][dc] == '.') {
                     dr += i;
                     dc += j;
                 }

                 if(dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[dr].length() && grid[dr][dc] == '#') {
                     count++;
                 }
            }
        }

        newGrid[row][col] = count >= 5 ? 'L' : grid[row][col];

        return count >= 5;
    }



  private:
    std::vector<std::string> grid;

};

} // namespace day11