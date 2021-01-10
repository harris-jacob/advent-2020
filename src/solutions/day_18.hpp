#pragma once

#include "solutions.hpp"
#include "read_file.hpp"
#include <memory>
#include <vector>
#include <string>

namespace day18
{

  class Day18 : public solutions::Solution
  {
  public:
    static std::unique_ptr<solutions::Solution> create()
    {
      return std::make_unique<Day18>();
    }

    // Solve part one
    std::string partOne(std::istream &input) override
    {
      // read input
      lines = utils::readStrInput(input);
      int sum = 0;
      for (auto &line : lines)
      {
        sum += doMaths(line);
      }
    }

    int solveLine(std::string &s)
    {
      // strip spaces
      s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
      // handle all brackets
      handleBrackets(s);

      // call doMaths a final time
      return doMaths(s);
      // return sum
    }

    void handleBrackets(std::string &line)
    {
      // Find the first ) and take index.
      // Recurse back and find corresponding (
      // call doMaths on ( to ). Store output in temp_var
      // Remove ( to ) replace with temp_var
      // Recurse
      for ()
    }

    int doMaths(std::string &s)
    {
      int sum = 0;
      // loop through
      for ()
        // if * do i-1 * i+1 -> result to sum
        // elif i == + do i-1 + i+1 -> result to sum
        return sum;
    }

    // Solve part two
    std::string partTwo(std::istream &input)
    {
    }

  private:
    std::vector<std::string> lines;
  };

} // namespace day18