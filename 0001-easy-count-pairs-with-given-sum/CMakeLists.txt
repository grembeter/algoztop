cmake_minimum_required(VERSION 3.16)

project(solution-1 C)

set(CMAKE_C_FLAGS
  "-std=iso9899:1999 -Wall -Wstrict-prototypes -Wmissing-prototypes -pedantic"
  " -Werror -Wconversion -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align"
  )

string(REGEX REPLACE ";" " " CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} CACHE STRING "")

set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb" CACHE STRING "")
set(CMAKE_C_FLAGS_RELEASE "-Os -DNDEBUG" CACHE STRING "")

include_directories("include")

add_library(hashset STATIC "hashset.c")
add_executable(${CMAKE_PROJECT_NAME} "hashset-test.c")
target_link_libraries(${CMAKE_PROJECT_NAME} hashset)

enable_testing()

add_test(hashset-test solution-1)
