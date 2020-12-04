#pragma once 
#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>

namespace solutions {

// https://stackoverflow.com/questions/11175379/register-a-c-class-so-that-later-a-function-can-iterate-over-all-registered-cl
// https://github.com/thomas-gale/advent-of-code/blob/377d77d4129e9791f1811a70c245f9033ec8bfe2/src/utilities/Solution.hpp
class Solution {
  public:  
    using SolutionPtr = std::unique_ptr<Solution>;
    
    virtual ~Solution() = default;
    
    // instantiate a solution from the map
    static std::unique_ptr<Solution> instantiate(int day){
        auto it = registry().find(day);
        return it == registry().end() ? nullptr : std::move(it->second);
    }

    template <typename T> class Registrar {
      public:
        explicit Registrar(int day, std::string description) {
            auto newSol = T::create();
            newSol->description = description;
            Solution::registrate(day, std::move(newSol));
        }
    };

    virtual int partOne(std::istream& input) = 0;
    virtual int partTwo(std::istream& input) = 0;
    
    std::string description;
  
  protected:
    // add a solution to the map
    static void registrate(int day, SolutionPtr fp) {
        registry()[day] = std::move(fp);
    }

private:
    static std::unordered_map<int, SolutionPtr>& registry();
};

} // namespace solutions