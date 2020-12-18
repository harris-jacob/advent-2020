#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cmath>
#include <set>
#include "solutions.hpp"
#include "read_file.hpp"

namespace day14 {

class Day14: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day14>();
    }

    std::string partOne(std::istream& input) override {
        auto commands = parse(input);
        std::map<int, long> memory;

        for (auto command : commands) {
            if(command.first == "mask") {
                mask = command.second;
            }
            else if(command.first.substr(0, 3) == "mem"){ 
                auto mem_addr = command.first.substr(4);
                mem_addr.pop_back();
                long val = maskMutate(std::stoi(command.second));
                memory[std::stoi(mem_addr)] = val;
             }
        }

        // sum memory
        long result = 0;
        for(auto const& x : memory) {
            result+=x.second;
        }

        return std::to_string(result);
    }

    std::string partTwo(std::istream& input) override {
        auto commands = parse(input);
        std::map<long, long> memory;

        for (auto command : commands) {
            if(command.first == "mask") {
                mask = command.second;
            }

            else if(command.first.substr(0, 3) == "mem"){ 
                auto mem_addr = command.first.substr(4);
                mem_addr.pop_back();
                auto vals = maskMutateP2(std::stoi(mem_addr));
                
                for(auto val : vals ) {
                    memory[val] = std::stoi(command.second);
                }
            }
        }

        // sum memory
        long result = 0;
        for(auto const& x : memory) {
            result+=x.second;
        }

        return std::to_string(result);

    }

  private:
    std::string mask;


    std::set<long> maskMutateP2(long num) {
        std::vector<int> floats;  
        std::set<long> nums;
        for(std::string::size_type i=0; i< 36; ++i) {
            // turn all 1s in both mask and num to zero
            long exp = std::pow(2, 35 - i);

            if(mask[i] == '1') {
                num |= exp;
            }

            else if(mask[i] == 'X') {
                floats.push_back(i);
                // NOTE i wasn't using UL at first and it broke my code and took me hours to figure out.
                num &= ~(1UL << (35-i));
            }
        }

        // add the initial val
        nums.insert(num);

        auto eval_floats = evalFloats(floats, nums);
        auto comb = std::pow(2, floats.size());
        
        if(eval_floats.size() != comb) {
            throw std::runtime_error("combinations");
        }

        return eval_floats;

    }

    std::set<long> evalFloats(std::vector<int> floats, std::set<long>& nums) {
        if(floats.size() == 0) {
            return nums;
        } 

        int index = floats[0];
        floats.erase(floats.begin());

        long exp = std::pow(2, 35 - index);

        for(auto const num : nums) {
            long new_val = num | exp;
            if(nums.count(new_val) != 0) {
                continue;
            }
            nums.insert(new_val);
        }

        return evalFloats(floats, nums);

    }

    
    long maskMutate(int num) {
        std::string bin_val = toBinary(num);
        auto a = mask.length();
        auto b = bin_val.length();
        for(std::string::size_type i=0; i< 36; ++i) {
            if(mask[i] == '0' || mask[i] == '1') {
                bin_val[i] = mask[i];
            }
        }

        return toDecimal(bin_val);
    }

    // convert dec to binary of 32 bits.
    std::string toBinary(int n){
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}

    r.insert(r.begin(), 36 - r.length(), '0');

    return r;
    }


    // Function to convert binary to decimal
    long toDecimal(std::string n){
        std::string num = n;
        long dec_value = 0;
        long base = 1;

        while (n != "") {
            long last_digit = std::stoi(n.substr(n.length()-1)) % 10;
            
            n.pop_back();
    
            dec_value += last_digit * base;
    
            base = base * 2;
        }
    
        return dec_value;
    }
 

    std::vector<std::pair<std::string, std::string>> parse(std::istream& input) {
        auto str_input = utils::readStrInput(input);
        std::vector<std::pair<std::string, std::string>> commands;

        // do a bit of parsing
        for(auto s : str_input) {
            size_t pos;
            pos = s.find(" = ");
            std::pair<std::string, std::string> command{ s.substr(0, pos), s.substr(pos+3, s.length() -1) };
            commands.push_back(command);
        }

        return commands;
    }
};

} // namespace day14