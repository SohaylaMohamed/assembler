cmake_minimum_required(VERSION 3.10)
project(assemblerPass1)

set(CMAKE_CXX_STANDARD 11)

add_executable(assemblerPass1 Operands/OpGroups.cpp Operands/OpGroups.h Line.cpp Line.h LinesConfiguration.cpp
        LinesConfiguration.h Literal.cpp Literal.h Expressions.cpp Expressions.h readFile.cpp readFile.h operations.cpp operations.h Operands/OpGroup1.cpp Operands/OpGroup1.h
        Operands/OpGroup2.cpp Operands/OpGroup2.h Operands/OpGroup3.cpp Operands/OpGroup3.h Operands/OpGroup4.cpp Operands/OpGroup4.h
        Operands/OpGroup5.cpp Operands/OpGroup5.h Operands/OpGroup6.cpp Operands/OpGroup6.h main.cpp Operands/OpGroup7.cpp Operands/OpGroup7.h
        Operands/OpGroup8.cpp Operands/OpGroup8.h Operands/OpGroup9.cpp Operands/OpGroup9.h Operands/OpGroup10.h
        Operands/OpGroup10.cpp Address.cpp Address.h writeFile.cpp writeFile.h SymTable.cpp SymTable.h Operands/OpGroup11.cpp
        Operands/OpGroup11.h)
