cmake_minimum_required(VERSION 3.28)
project(semproj)

set(CMAKE_CXX_STANDARD 17)

add_executable(semproj src/main.cpp
        src/csv_reader.cpp
        src/csv_reader.h
        test/test_csv_reader.cpp
        test/test_fixtures.cpp
        src/fixtures.h
        src/fixtures.cpp)
