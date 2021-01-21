cmake_minimum_required(VERSION 3.16)
enable_testing()
project("common_test")

set("common_test_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/LowLevelSimulator.cpp)
set("common_test_include" ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library("${PROJECT_NAME}" ${common_test_sources})
target_include_directories("${PROJECT_NAME}" PUBLIC "${common_test_include}")
target_link_libraries("${PROJECT_NAME}" PRIVATE "Configuration")

#TODO add tests

