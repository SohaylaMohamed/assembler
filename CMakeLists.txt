cmake_minimum_required(VERSION 3.10)
project(assemblerPass1)

set(CMAKE_CXX_STANDARD 11)

add_executable(assemblerPass1 main.cpp OpGroups.cpp OpGroups.h OpGroup1.cpp OpGroup2.cpp OpGroup3.cpp OpGroup4.cpp OpGroup5.cpp OpGroup6.cpp Line.cpp Line.h LinesConfiguration.cpp LinesConfiguration.h readFile.cpp readFile.h)
