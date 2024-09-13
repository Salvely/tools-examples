cmake_minimum_required(VERSION 3.20)
project(doctest)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/doctest)
add_executable(tutorials "src/tutorials.cpp")
target_link_libraries(tutorials doctest)

include(CTest)
enable_testing()
add_test(NAME tutorials_test COMMAND tutorials)