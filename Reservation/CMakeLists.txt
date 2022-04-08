cmake_minimum_required(VERSION 3.21)
project(Reservation)

set(CMAKE_CXX_STANDARD 14)

add_executable(Reservation main.cpp globalFile.h orderFile.cpp orderFile.h computerRoom.h manager.cpp manager.h identity.h student.cpp student.h teacher.cpp teacher.h)

