#pragma once
#include "read_file.hpp"
#include "solutions.hpp"
#include <cstdlib>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace day13 {

class Day13 : public solutions::Solution {
public:
  static std::unique_ptr<solutions::Solution> create() {
    return std::make_unique<Day13>();
  }

  std::vector<int> parseBuses(std::string &input) {
    std::stringstream stream(input);
    std::string item{};
    std::vector<int> split;
    while (std::getline(stream, item, ',')) {
      if (item != "x")
        split.push_back(std::stoi(item));
    }
    return split;
  }

  std::vector<std::string> parseBusesP2(std::string &input) {
    std::stringstream stream(input);
    std::string item{};
    std::vector<std::string> split;
    while (std::getline(stream, item, ',')) {
      split.push_back(item);
    }
    return split;
  }

  std::string partOne(std::istream &input) override {
    auto instructions = utils::readStrInput(input);
    auto time = std::stoi(instructions[0]);
    std::vector<int> buses = parseBuses(instructions[1]);

    std::pair<int, int> best = {0, std::numeric_limits<int>::max()};
    for (auto bus : buses) {
      int time_cpy = time;
      while (true) {
        if (time_cpy % bus == 0) {
          if (time_cpy < best.second) {
            best.second = time_cpy;
            best.first = bus;
          }
          break;
        }
        time_cpy++;
      }
    }

    return std::to_string((best.second - time) * best.first);
  }
  // thanks to Reddit, this guy:
  // https://www.youtube.com/watch?v=ru7mWZJlRQg&t=323s && this guy:
  // https://www.youtube.com/watch?v=x40aLK9KjYQ&t=1393s. Because I was lost
  // here :(
  std::string partTwo(std::istream &input) override {
    auto instructions = utils::readStrInput(input);
    auto time = std::stoi(instructions[0]);
    std::vector<std::string> buses = parseBusesP2(instructions[1]);
    // Target mod value and bus number
    std::vector<std::pair<int, int>> constraints;
    // product of all required
    long N = 1;
    for (int i = 0; i < buses.size(); ++i) {
      if (buses[i] != "x") {
        int bus = std::stoi(buses[i]);
        int a = i % bus;
        constraints.push_back({(bus - a) % bus, bus});
        // Keep track of sum
        N *= bus;
      }
    }

    long ans = 0;
    for (int i = 0; i < constraints.size(); ++i) {
      // used to cancel out other terms so we can solve mods independently
      // need to find a multiple of multiplier such that target%bus=i
      long multiplier = N / constraints[i].second;
      long mod_inverse = modInverse(multiplier, constraints[i].second);
      ans += constraints[i].first * mod_inverse * multiplier;
    }
    ans %= N;
    return std::to_string(ans);
  }

private:
  // calc mod inverse from:
  // https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
  long modInverse(long a, long m) {
    int g = gcd(a, m);
    if (g != 1) {
      throw std::invalid_argument("Modulo inverse does not exist");
    }

    else {
      return power(a, m - 2, m);
    }
  }

  // To compute x^y under modulo m
  long power(long x, unsigned long y, unsigned long m) {
    if (y == 0)
      return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
  }

  // Function to return gcd of a and b
  int gcd(long a, long b) {
    if (a == 0)
      return b;
    return gcd(b % a, a);
  }
};

} // namespace day13