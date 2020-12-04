#include "register.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

// TODO figure out how to not make this depend on the working dir.
const std::string _INPUT_DIR = "./input/";

int main(int arcg, char** argv) { 
    if (argc != 1) {
        throw std::invalid_argument(
            "Expected single arg for day. e.g.: 1)";
    }
    
    int day = atoi(argv[0]);

    int solutions;
    switch (day)
    {
    case 1:
      

    
    default:
      break;
    }

}