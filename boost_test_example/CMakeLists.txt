# configure the project 
cmake_minimum_required(VERSION 3.20)
set(CXX_STANDARD_REQUIRED 11)
project(learn_boost)

# set library and executable output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# add library to the project
add_library(boost_test_lib STATIC src/reverse.cpp)

# add executable and libaray
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# include directories
target_include_directories(boost_test_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE boost_test_lib)

# find_package
set(Boost_ROOT_DIR "C:/Program Files/Boost/boost_1_84_0")
find_package(Boost REQUIRED)
if(BOOST_FOUND)
        message("boost found")
endif()

# add boost test
enable_testing()

# add executable
file(GLOB TEST_SOURCE "test/*.cpp")
add_executable(boost_test ${TEST_SOURCE} src/reverse.cpp)
# include the directories
target_include_directories(boost_test PUBLIC ${PROJECT_SOURCE_DIR}/include)