cmake_minimum_required(VERSION 3.20)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o2")

add_executable(Lab4 main.cpp TextAnalyzer.cpp TextAnalyzer.h ParallelFirst.cpp ParallelFirst.h Single.cpp Single.h Parallel.cpp Parallel.h)
