cmake_minimum_required(VERSION 3.24)
project(Elaborato)

set(CMAKE_CXX_STANDARD 17)

add_executable(Elaborato main.cpp Conto.cpp Conto.h Transazione.cpp Transazione.h Data.cpp Data.h)
