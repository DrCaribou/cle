cmake_minimum_required(VERSION 3.17)
project(cle CXX)

find_package(GTest)

add_executable(cle-test main.cpp)
target_link_libraries(cle-test GTest::GTest GTest::Main)
