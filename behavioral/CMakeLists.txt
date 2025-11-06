cmake_minimum_required(VERSION 3.22)

project(behavioral LANGUAGES CXX)

# Chain of responsibility pattern
add_executable(purchase chain/purchase/main.cc)
add_executable(leave chain/leave/main.cc)
