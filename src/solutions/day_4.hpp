#pragma once
#include <string>
#include <istream>
#include <regex>
#include <vector>
#include <unordered_map>
#include "solutions.hpp"
#include "read_file.hpp"


namespace day4 {

class Day4 : public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day4>();
    }

    std::string partOne(std::istream& input) override {
        int count = 0;
        const std::regex e("([a-zA-Z0-9_]+):([^. ]+)");

         std::vector<std::string> passports = utils::readLnDelimiterInput(input);

        for (const std::string& passport : passports) {
            std::vector<std::string> keys;
            std::smatch m;
            std::string::const_iterator s(passport.cbegin());

            while(std::regex_search(s, passport.cend(), m, e)) {

                if(m[1].str() != "cid") {
                    keys.push_back(m[1].str());
                }

                s = m.suffix().first;
            }

            if(keys.size() == 7) {
                count ++;
            }
        }

        return std::to_string(count);
    }

    bool check_height(std::string hgt) {
        std::smatch m;
        std::regex r("([0-9]+)(cm|in)");

        if(std::regex_match(hgt, m, r)) {
            if(m[2].str() == "cm") return std::stoi(m[1].str()) >= 150 && std::stoi(m[1].str()) <= 193;
            if (m[2].str() == "in") return std::stoi(m[1].str()) >= 59 && std::stoi(m[1].str()) <= 76;
            return false;
        }
        return false;
    }

    bool check_ecl(std::string ecl) {
        const std::vector<std::string> valid_ecl{
                "amb", "blu", "brn", "gry", "grn", "hzl", "oth"
            };
            return std::find(valid_ecl.begin(), valid_ecl.end(), ecl) != valid_ecl.end();
    }

    bool validate(std::unordered_map<std::string, std::string> m) {
        if(m.size() != 7) {
            return false;
        }

        if(std::stoi(m["byr"]) < 1920 || std::stoi(m["byr"]) > 2002){
            return false;
        }

        if(std::stoi(m["iyr"]) < 2010 || std::stoi(m["iyr"]) > 2020) {
            return false;
        }
        if(std::stoi(m["eyr"]) < 2020 || std::stoi(m["eyr"]) > 2030) {
            return false;
        }
        if(!check_height(m["hgt"])) {
            return false;
        }

        if(!check_ecl(m["ecl"])) {
            return false;
        }

        if(!regex_match(m["pid"].cbegin(), m["pid"].cend(), std::regex("[0-9]{9}+"))) {
            return false;
        }

        if(!regex_match(m["hcl"].cbegin(), m["hcl"].cend(), std::regex("#([0-9]|[a-f]){6}+"))) {
            return false;
        }
        return true;
    }

    std::string partTwo(std::istream& input) override {
        int count = 0;
        const std::regex e("([a-zA-Z0-9_]+):([^. ]+)");
         std::vector<std::string> passports = utils::readLnDelimiterInput(input);

        for (const std::string& passport : passports) {
            std::unordered_map<std::string, std::string> passport_map;
            std::smatch m;
            std::string::const_iterator s(passport.cbegin());

            while(std::regex_search(s, passport.cend(), m, e)) {

                if(m[1].str() != "cid") {
                    std::string key = m[1].str();
                    std::string value = m[2].str();
                    passport_map[key] = value;
                }

                s = m.suffix().first;
            }

            if(validate(passport_map)) {
                count++;
            }
        }

        return std::to_string(count);
    }
};

} // namespace day4