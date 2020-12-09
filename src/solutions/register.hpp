#include "day_1.hpp"
#include "day_2.hpp"
#include "day_3.hpp"
#include "day_4.hpp"
#include "day_5.hpp"
#include "day_6.hpp"
#include "day_7.hpp"
#include "day_8.hpp"

#include "solutions.hpp"

namespace solutions {

Solution::Registrar<day1::Day1> r01(1, "Report Repair");
Solution::Registrar<day2::Day2> r02(2, "Password Philosophy");
Solution::Registrar<day3::Day3> r03(3, "Toboggan Trajectory");
Solution::Registrar<day4::Day4> r04(4, "Passport Processing");
Solution::Registrar<day5::Day5> r05(5, "Passport Control");
Solution::Registrar<day6::Day6> r06(6, "Custom Customs");
Solution::Registrar<day7::Day7> r07(7, "Handy Haversacks");
Solution::Registrar<day8::Day8> r08(8, "Handheld Halting");
}