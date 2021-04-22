cmake_minimum_required(VERSION 3.16)

project(solution C)

include("../common-problem.cmake")

include_directories("include")

add_library(${CMAKE_PROJECT_NAME}-1 STATIC "hashset.c")
#add_executable(test-${CMAKE_PROJECT_NAME}-1 "tests/test-solution-1.c")
add_executable(test-${CMAKE_PROJECT_NAME}-1 "hashset-test.c")
target_link_libraries(test-${CMAKE_PROJECT_NAME}-1 solution-1)
#target_link_libraries(test-${CMAKE_PROJECT_NAME}-1 check pthread m rt subunit solution-1)

enable_testing()

add_test(NAME ${CMAKE_PROJECT_NAME}-1 COMMAND test-${CMAKE_PROJECT_NAME}-1)
