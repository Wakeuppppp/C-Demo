cmake_minimum_required(VERSION 3.21)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestProject main.cpp worker.h workerMgr.cpp workerMgr.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)
