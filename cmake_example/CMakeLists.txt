cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

project(hello-cmake)
# set(CMAKE_GENERATOR "MinGW Makefiles")

file(GLOB SOURCES "src/*.cpp")
# set(SOURCES src/hello.cpp src/main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

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
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system unit_test_framework)
if(Boost_FOUND)
    message ("boost found")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE Boost::filesystem)
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

# apply cppcheck to the project
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

# apply clang-format to the project
set(CLANG_FORMAT_BIN_NAME clang-format)
set(CLANG_FORMAT_EXCLUDE_PATTERNS  "build/" ${CMAKE_BINARY_DIR})
find_package(CLANG_FORMAT)

# apply boost testing to the project 
add_library(boost_test_lib src/reverse.cpp src/palidrome.cpp)
target_include_directories(boost_test_lib PUBLIC ${PROJECT_SOURCE_DIR}/include/static)
target_link_libraries(boost_test_lib PUBLIC Boost::boost)

enable_testing()
add_executable(unit_tests ${PROJECT_SOURCE_DIR}/test/boost_test.cpp)
target_include_directories(unit_tests PUBLIC ${PROJECT_SOURCE_DIR}/include/static)
target_link_libraries(unit_tests boost_test_lib Boost::unit_test_framework)
target_compile_definitions(unit_tests
    PRIVATE
        BOOST_TEST_DYN_LINK
)
add_test(NAME test_boost COMMAND unit_tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# apply googletest to the project
include_directories("D:/Program_Files/Git/usr/lib/googletest-distribution/include/")
link_directories("D:/Program_Files/Git/usr/lib/googletest-distribution/lib/")
find_package(GTest REQUIRED)
add_executable(google_unit_tests ${PROJECT_SOURCE_DIR}/test/googletest_test.cpp)
target_include_directories(google_unit_tests PUBLIC ${PROJECT_SOURCE_DIR}/include/static)
target_link_libraries(google_unit_tests boost_test_lib  pthread gtest gtest_main)
add_test(NAME test_google COMMAND google_unit_tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add doxygen to the project
# add_subdirectory(bin)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(Doxygen)
find_package(doxygen)
Doxygen(src docs)

# pack the project

# set a project version
set (deb_example_VERSION_MAJOR 0)
set (deb_example_VERSION_MINOR 2)
set (deb_example_VERSION_PATCH 2)
set (deb_example_VERSION "${deb_example_VERSION_MAJOR}.${deb_example_VERSION_MINOR}.${deb_example_VERSION_PATCH}")

############################################################
# Install
############################################################

# Binaries
install (TARGETS ${PROJECT_NAME}
    DESTINATION bin)

# # Library
# # Note: may not work on windows
# install (TARGETS cmake_examples_deb
#     LIBRARY DESTINATION lib)

# # Config
# install (FILES cmake-examples.conf
#     DESTINATION etc)

############################################################
# Create DEB
############################################################

# Tell CPack to generate a .deb package
set(CPACK_GENERATOR "DEB")

# Set a Package Maintainer.
# This is required
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Thom Troy")

# Set a Package Version
set(CPACK_PACKAGE_VERSION ${deb_example_VERSION})

# Include CPack
include(CPack)