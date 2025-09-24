cmake_minimum_required(VERSION 3.22)

project(structural LANGUAGES CXX)

add_executable(operation adapter/score_operation/main.cc)
add_executable(encryptor adapter/encryptor/main.cc)