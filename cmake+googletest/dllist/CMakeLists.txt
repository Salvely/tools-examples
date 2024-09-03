cmake_minimum_required(VERSION 3.20)
set(CXX_STANDARD_REQUIRED 11)
project(dllist)

file(GLOB SOURCES "src/*.cpp")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/include/static)
add_library(greet_lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/static)

target_link_libraries(${PROJECT_NAME} PRIVATE greet_lib)