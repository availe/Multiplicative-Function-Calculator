cmake_minimum_required(VERSION 3.30)
project(Multiplicative_Function_Calculator)

set(CMAKE_CXX_STANDARD 23)

add_executable(Multiplicative_Function_Calculator main.cpp
        formatting.cpp
        formatting.h
        primes.cpp
        primes.h
        multiplicative.cpp
        multiplicative.h)
