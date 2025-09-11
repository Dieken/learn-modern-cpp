cmake_minimum_required(VERSION 3.31)
project(main VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(Backward CONFIG REQUIRED)

############################################################
add_executable(main main.cpp backward.cpp)

target_link_libraries(main PRIVATE
    fmt::fmt
    spdlog::spdlog
    Backward::Interface)

############################################################
add_executable(test1 test1.cpp backward.cpp)

target_link_libraries(test1 PRIVATE
    doctest::doctest
    Backward::Interface)

############################################################
add_executable(test2 test2.cpp backward.cpp)

target_link_libraries(test2 PRIVATE
    Catch2::Catch2WithMain
    Backward::Interface)

############################################################
include(doctest)
include(Catch)

doctest_discover_tests(test1)
catch_discover_tests(test2)
