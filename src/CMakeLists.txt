add_subdirectory(utils)
add_subdirectory(solutions)

add_executable(main 
    main.cpp
)

target_include_directories(main PRIVATE
  ${solutions_SOURCE_DIR}
)

target_link_libraries(main PUBLIC 
# src
utils
solutions
)