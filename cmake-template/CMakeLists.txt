cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

project(hello-cmake)
# set(CMAKE_GENERATOR "MinGW Makefiles")

file(GLOB SOURCES "src/*.cpp")
# set(SOURCES src/hello.cpp src/main.cpp)

# add static library
add_library(hello_lib STATIC src/hello_static.cpp)
target_include_directories(hello_lib PUBLIC ${PROJECT_SOURCE_DIR}/include/static)

# add shared library
add_library(hello_shared_lib SHARED src/hello_shared.cpp)
# add_library(hello::shared::lib hello_shared_lib) # alias the library
target_include_directories(hello_shared_lib PUBLIC ${PROJECT_SOURCE_DIR}/include/shared)

# # include subdir1
# add_subdirectory(subdir1)
# # include subdir2
# add_subdirectory(subdir2)
# # include subdir3
# add_subdirectory(subdir3)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE hello_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE hello_shared_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE subdir1)
target_link_libraries(${PROJECT_NAME} PRIVATE subdir2)
target_link_libraries(${PROJECT_NAME} PRIVATE subdir3)

set(BOOST_ROOT "C:/Program Files/Boost/boost_1_84_0")
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
if(Boost_FOUND)
    message ("boost found")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE Boost::filesystem)
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

# apply cpp check to the project
# Add a custom CMake Modules directory
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})
find_package(CPPCHECK)
# static analysis. Should be before adding subprojects
set (ALL_ANALYSIS_TARGETS)
add_subdirectory(subdir1)
add_subdirectory(subdir2)
add_subdirectory(subdir3)
if( CPPCHECK_FOUND )
    add_custom_target(analysis)
    ADD_DEPENDENCIES(analysis ${ALL_ANALYSIS_TARGETS})
    set_target_properties(analysis PROPERTIES EXCLUDE_FROM_ALL TRUE)
    message("analysis analysis targets are ${ALL_ANALYSIS_TARGETS}")
endif()

# install process # , SEE [HERE](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/E-installing)
# install(TARGETS cmake_example_inst_bin DESTINATION bin)
# Binaries
# Library
# Header file
# Config