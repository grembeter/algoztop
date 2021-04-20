cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_FLAGS
  "-std=iso9899:1999 -Wall -Wstrict-prototypes -Wmissing-prototypes -pedantic"
  " -Werror -Wconversion -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align"
  )

string(REGEX REPLACE ";" " " CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} CACHE STRING "")

set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb" CACHE STRING "")
set(CMAKE_C_FLAGS_RELEASE "-Os -DNDEBUG" CACHE STRING "")

