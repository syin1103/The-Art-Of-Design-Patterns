cmake_minimum_required(VERSION 3.22)

project(structural LANGUAGES CXX)

# Adapter Pattern
add_executable(operation adapter/score_operation/main.cc)
add_executable(encryptor adapter/encryptor/main.cc)

# Bridge Pattern
add_executable(image bridge/image/main.cc)
add_executable(file_converter bridge/converter/main.cc)

# Composite Pattern
add_executable(kill_virus composite/virus/main.cc)
add_executable(ui_control composite/control/main.cc)