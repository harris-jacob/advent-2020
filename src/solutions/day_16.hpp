#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include "solutions.hpp"
#include "read_file.hpp"

namespace day16 {

class Day16: public solutions::Solution {
  public:

    static std::unique_ptr<solutions::Solution> create() {
        return std::make_unique<Day16>();
    }

    std::string partOne(std::istream& input) override {
        parse_tickets(input);
        int sum = 0;
        for(const auto& ticket : nearby_tickets) {
            for(const auto& field : ticket) {
                bool valid = false;
                for(auto item : ticket_fields) {
                    if((field >= item.lower_bounds.first && field <= item.lower_bounds.second) 
                    || (field >= item.upper_bounds.first && field <= item.upper_bounds.second)) {
                        valid = true;
                    }
                }

                if(!valid) {
                    sum+=field;
                }
            }
        }

        return std::to_string(sum);
    }

    std::string partTwo(std::istream& input) override {
        // thow out invalid
        parse_tickets(input);
        int sum = 0;
        std::vector<std::vector<int>> valid_tickets{};
        for(int i=0; i<nearby_tickets.size(); ++i) {
            bool add_ticket = true;
            for(auto field : nearby_tickets[i]) {
                bool valid = false;
                for(auto item : ticket_fields) {
                    if((field >= item.lower_bounds.first && field <= item.lower_bounds.second) 
                    || (field >= item.upper_bounds.first && field <= item.upper_bounds.second)) {
                        valid = true;
                    }
                }
                if(!valid) {
                    add_ticket=false;
                }
            }

            if(add_ticket) {
                valid_tickets.push_back(nearby_tickets[i]);
            }
        }

        // construct eval matrix
        std::vector<std::vector<bool>> eval_matrix(ticket_fields.size());
        for(int i=0; i<eval_matrix.size(); ++i) {
            std::vector<bool> bools(ticket_fields.size());
            std::fill(bools.begin(), bools.end(), true);
            eval_matrix[i] = bools;
        }

        // figure out mappings that work
        for(auto ticket : valid_tickets) {
            for(int i=0; i<ticket.size(); ++i) {
                auto field = ticket[i];
                for(int j=0; j<ticket_fields.size(); ++j) {
                    auto item = ticket_fields[j];
                    if(!(item.lower_bounds.first <= field && item.lower_bounds.second >= field) 
                    && !(item.upper_bounds.first <= field && item.upper_bounds.second >= field)) {
                        eval_matrix[i][j] = false;
                    }
                }
            }
        }


        // count out matches with one posibility
        std::vector<int> used{};
        std::map<int, int> mapping;
        while( used.size() < ticket_fields.size() ) {
            for(int i=0; i< eval_matrix.size(); ++i) {
                int matches = 0;
                int match_pos;
                for(int j=0; j<eval_matrix[i].size(); ++j) {
                    std::vector<int>::iterator p = std::find(used.begin(), used.end(), j);
                    if(eval_matrix[i][j] && p==used.end()) {
                        match_pos = j;
                        matches++;
                    }
                }
                if(matches == 1) {
                    mapping[match_pos] = i;
                    used.push_back(match_pos);
                }
            }
        }

        // calc the sum
        long product=1;
        for(int i=0; i<6; ++i) {
            int mapped_val = mapping[i];
            product*=my_ticket[mapped_val];
        }


        return std::to_string(product);

    }

  private:
    void parse_tickets(std::istream& input) {
        auto str_input = utils::readStrInput(input);
        int j = 0;
        std::string item;
        std::stringstream stream;

        // handle map
        for(int i=0; i<str_input.size(); ++i) {
            stream.clear();
            stream.str(str_input[i]);
            std::vector<std::string> split_str;
            Field field;
            if(str_input[i] == "your ticket:") {
                j=i;
                break;
            }

            if(str_input[i] == "") {
                continue;
            }

            while(std::getline(stream, item, ':')) {
                split_str.push_back(item);
            };
            stream.clear();
            stream.str(split_str[1]);
            
            while(std::getline(stream, item, ' ')) {
                split_str.push_back(item);
            }

            // handle bounds
            field.set_lower(split_str[3]);
            field.set_upper(split_str[5]);

            // assign to map
            field.name = split_str[0];
            ticket_fields.push_back(field);

        }

        // handle my ticket
        for(int i=j+1; i<str_input.size(); ++i) {
            if(str_input[i] == "nearby tickets:") {
                j=i;
                break;
            }
            if(str_input[i] == "") {
                continue;
            }

            stream.clear();
            stream.str(str_input[i]);
            while (std::getline(stream, item, ',')) {
                 my_ticket.push_back(std::stoi(item));
            }
        }

        // handle nearby tickets
        for(int i=j+1; i<str_input.size(); ++i) {
            std::vector<int> ticket;
            stream.clear();
            stream.str(str_input[i]);
            while (std::getline(stream, item, ',')) {
                ticket.push_back(std::stoi(item));
            }
            nearby_tickets.push_back(ticket);
        }
        
    }

    class Field {
      public:
        void set_lower(std::string& str) {
        std::stringstream stream(str);

        stream >> lower_bounds.first;
        stream >> lower_bounds.second;    
        lower_bounds.second = abs(lower_bounds.second);
        }

        void set_upper(std::string& str) {
        std::stringstream stream(str);

        stream >> upper_bounds.first;
        stream >> upper_bounds.second;    
        upper_bounds.second = abs(upper_bounds.second);
        }
        
        std::pair<int, int> lower_bounds;
        std::pair<int, int> upper_bounds;
        std::string name;
    };

    std::vector<Field> ticket_fields{};
    std::vector<int> my_ticket{};
    std::vector<std::vector<int>> nearby_tickets{};

};

} // namespace day16