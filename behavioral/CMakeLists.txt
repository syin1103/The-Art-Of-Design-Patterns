cmake_minimum_required(VERSION 3.22)

project(behavioral LANGUAGES CXX)

# Chain of responsibility pattern
add_executable(purchase chain/purchase/main.cc)
add_executable(leave chain/leave/main.cc)

# Command pattern
add_executable(caculator command/caculator/main.cc)
add_executable(menu command/menu/main.cc)

# Interpreter pattern
add_executable(format interpreter/format/main.cc)

# Iterator pattern
add_executable(product_list iterator/object_list/main.cc)

# Mediator pattern
add_executable(crm mediator/crm/main.cc mediator/crm/mediator.cc)
add_executable(pane mediator/pane/main.cc mediator/pane/mediator.cc)

# Memento pattern
add_executable(chessman memento/chessman/main.cc)
add_executable(rpg memento/rpg/main.cc)

# Observer pattern
add_executable(ally observer/ally/main.cc)
add_executable(stock observer/stock/main.cc)