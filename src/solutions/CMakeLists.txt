add_library(solutions
solutions.cpp
register.cpp
)

target_include_directories(solutions PUBLIC
    .
)

target_link_libraries(solutions PUBLIC 
utils
)