cmake_minimum_required(VERSION 3.14)
project(EinfachVerketteteListe)

set(CMAKE_CXX_STANDARD 14)

add_executable(EinfachVerketteteListe main.cpp List.cpp List.h ListNode.cpp ListNode.h)