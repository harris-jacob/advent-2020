#pragma once

#include "solutions.hpp"
#include "read_file.hpp"
#include <memory>
#include <vector>
#include <string>
#include <stack>
#include <map>

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
      auto tokens = utils::readStrInput(input)
    }

    // Solve part two
    std::string partTwo(std::istream &input) override
    {
    }

  private:
    std::stack<int> operands;
    std::stack<char> operators;

    std::map<char, int>precedence_map = {{'-', 0}, {'+', 1}, {'*', 2}, {'/', 3}};


    int djikstrasTwoStack(const std::string &input) {
      for(char& c : input) {
      }
    }

    int handleToken(const char& c) {
      switch(c) {
        case "(":
          handleLeftParenthesis();
          break;
        case ")":
          handleRightParenthesis();
          break;
        case "+":
        case "-":
        case "/":
        case "*":
          handleOperator(const char& c);
          break;
        default:
          handleNumber(const char& c);
          break;
      }
    }

    void handleLeftParenthesis() {
        operators.push('(');
    }
    void handleNumber(const char& c) {
      int num = std::atoi(c);
      operands.push(num);
    }

    void handleRightParenthesis() {
      char popped = operators.pop();

      while popped != '(' {
          int operand1 = operands.pop();
          int operand2 = operands.pop();

          applyOperator(val1, val2, operator)
      }

    }

    void handleOperator(const char& thisOp) {
        precidence = getPrecidence()
    }

    void applyOperator(int operand1, int operand2, char operator) {
        switch(operator) {
          case '+':
            operands.push(operand1 + operand2);
            break;
           case '-':
            operands.push(operand2 - operand1);
            break;
           case '*':
            operands.push(operand1*operand2);
            break;
           case '/':
            operands.push(operand2 / operand1);
            break;
           default:
            throw std::exception("Unknown operand");
        }
    }

    int getPrecidence(char c) {
      precedence_map[c]
    }



  };

} // namespace day18