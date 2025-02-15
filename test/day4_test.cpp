#include <gtest/gtest.h>
#include <vector>
#include <fstream>
#include "day_4.hpp"
#include "read_file.hpp"

namespace test {

TEST(day_4, loadInput) {

    // Arrange
    std::ifstream infile("./input/day_4.txt");

    //Act
    auto input = utils::readLnDelimiterInput(infile);

    //Assert
    EXPECT_EQ(input[0], "eyr:2029 iyr:2013 hcl:#ceb3a1 byr:1939 ecl:blu hgt:163cm pid:660456119");
    EXPECT_EQ(input[input.size() - 1], "iyr:2010 ecl:oth pid:455361219 hgt:153cm eyr:2027 hcl:#6b5442 byr:1965");
}

TEST(day_4, partOne) {

  // Arrange
  std::istringstream input(
    "cl:gry pid:860033327 eyr:2020 hcl:#fffffd\n"
    "byr:1937 iyr:2017 cid:147 hgt:183cm\n\n"
    "iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884\n"
    "hcl:#cfa07d byr:1929\n\n"
    "hcl:#ae17e1 iyr:2013\n"
    "eyr:202\n4"
    "ecl:brn pid:760753108 byr:1931\n"
    "hgt:179cm\n\n"
    "hcl:#cfa07d eyr:2025 pid:166559648\n"
    "iyr:2011 ecl:brn hgt:59in\n"
  );

    auto solution = day4::Day4();

    //Assert
    EXPECT_EQ(solution.partOne(input), "2");
}


TEST(day_4, partTwo) {

  // Arrange
  std::istringstream input(
        "eyr:1972 cid:100\n"
        "hcl:#18171d ecl:amb hgt:170 pid:186cm iyr:2018 byr:1926\n\n"

        "iyr:2019\n"
        "hcl:#602927 eyr:1967 hgt:170cm\n"
        "ecl:grn pid:012533040 byr:1946\n\n"

        "hcl:dab227 iyr:2012\n"
        "ecl:brn hgt:182cm pid:021572410 eyr:2020 byr:1992 cid:277\n\n"

        "hgt:59cm ecl:zzz\n"
        "eyr:2038 hcl:74454a iyr:2023\n"
        "pid:3556412378 byr:2007\n\n"

        "pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980\n"
        "hcl:#623a2f\n\n"

        "eyr:2029 ecl:blu cid:129 byr:1989\n"
        "iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm\n\n"

        "hcl:#888785\n"
        "hgt:164cm byr:2001 iyr:2015 cid:88\n"
        "pid:545766238 ecl:hzl\n"
        "eyr:2022\n\n"

        "iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719"
  );

    auto solution = day4::Day4();

    //Assert
    EXPECT_EQ(solution.partTwo(input), "4");
}

} // namespace test