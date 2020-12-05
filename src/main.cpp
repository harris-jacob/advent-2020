#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "solutions.hpp"
#include "register.hpp"


// TODO: GUI and some viz?
int main() { 
    int day;
    int part;

    // TODO: use boost to find filepath eventually
    std::string _PATH = "/workspaces/advent-2020/build/src/";

    std::cout << "what day would you like to solve?\n";
    std::cin >> day;

    // Get the solution for that day
    auto solution = solutions::Solution::instantiate(day);
    if (!solution) {
        throw std::invalid_argument("solution for that day not found :(");
    }

    // Read input
    std::stringstream ss;
    ss << _PATH << "day_" << day << ".txt";
    std::fstream input(ss.str());

    if(!input) {
        throw std::invalid_argument("Cannot find the input file for this day. Check the input folder.");
    };
    
    std::cout << "Would you like to solve part 1 or part 2?\n";
    std::cin >> part;

    if(part != 1 && part != 2) {
        throw std::invalid_argument("Invalid input, please input either 1 or 2");
    }

    if(part == 1) {
        std::cout << "answer: " << solution->partOne(input) << "\n";
    } else {
        std::cout << "answer: " << solution->partTwo(input) << "\n";
    }

}