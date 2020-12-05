add_library(solutions
solutions.cpp
)


target_include_directories(solutions PUBLIC
    .
)

target_link_libraries(solutions PUBLIC 
utils
)