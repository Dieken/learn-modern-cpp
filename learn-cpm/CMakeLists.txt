cmake_minimum_required(VERSION 3.31)
project(main VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#11.2.0")
CPMAddPackage("gh:gabime/spdlog@1.15.3")
CPMAddPackage("gh:doctest/doctest@2.4.12")
CPMAddPackage("gh:catchorg/Catch2@3.10.0")
CPMAddPackage("gh:bombela/backward-cpp#0bfd0a07a61551413ccd2ab9a9099af3bad40681")

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
include(${DOCTEST_CMAKE_HELPER})
include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)

doctest_discover_tests(test1)
catch_discover_tests(test2)
