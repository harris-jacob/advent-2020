add_subdirectory(utils)
add_subdirectory(solutions)

add_executable(main 
    main.cpp
)

file(GLOB INPUT ../input/*.txt)
file(COPY ${INPUT} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(main PRIVATE
  ${solutions_SOURCE_DIR}
)

target_link_libraries(main PUBLIC 
# src
utils
solutions
)
