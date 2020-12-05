#include "day_1.hpp"
#include "day_2.hpp"
#include "day_3.hpp"
#include "solutions.hpp"

namespace solutions {

Solution::Registrar<day1::Day1> r01(1, "Report Repair");
Solution::Registrar<day2::Day2> r02(2, "Password Philosophy");
Solution::Registrar<day3::Day3> r03(3, "Toboggan Trajectory");
}