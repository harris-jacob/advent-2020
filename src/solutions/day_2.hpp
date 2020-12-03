#pragma one
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

namespace day2 {

struct Password {
    int min;
    int max;
    char target;
    std::string password;
};

// Construct passwords from inputs
Password createPassword(std::string &input) {
    Password password;
    std::string item{};
    std::stringstream stream(input);
    std::vector<std::string> split_str{};


    while(std::getline(stream, item, ' ')) {
        split_str.push_back(item);
    };
    
    // store min and max
    stream.str(split_str[0]);
    stream.clear();
    stream >> password.min;
    stream >> password.max;    
    password.max = abs(password.max);

    // get the target char
    password.target = split_str[1].at(0);
    
    // password is the rest
    password.password = split_str[2];

    return password;


}

// Solve part 1
int partOne(std::vector<std::string> input) {
    // count of valid passwords
    int count = 0;

    // Construct passwords
    for (int i=0; i<input.size(); ++i) {
        auto password = createPassword(input[i]);

        int n = std::count(password.password.begin(), password.password.end(), password.target);

        if(n >= password.min && n <= password.max ) {
            count++;
        }
    }
    return count;
}

// Solve part 2
int partTwo(std::vector<std::string> input) {
    // count of valid passwords
    int count = 0;

    // Construct passwords
    for (int i=0; i<input.size(); ++i) {
        auto password = createPassword(input[i]);

        if((password.password[password.max-1] == password.target && password.password[password.min-1] != password.target) || 
        (password.password[password.min-1] == password.target &&  password.password[password.max-1] != password.target)) {
            count++;
        }
    }
    return count;
}


} // namespace day2