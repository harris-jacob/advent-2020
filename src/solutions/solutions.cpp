#include "solutions.hpp"
#include <unordered_map>

namespace solutions {

std::unordered_map<int, Solution::SolutionPtr>& Solution::registry(){
    static std::unordered_map<int, Solution::SolutionPtr> impl;
    return impl;
}

} // namespace solutions