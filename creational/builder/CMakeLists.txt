project(Builder LANGUAGES CXX)

add_executable(actor_test actor/actor_test.cc)

add_executable(interface_test player/interface_test.cc)
set_target_properties(interface_test PROPERTIES
   CXX_STANDARD 20
   CXX_STANDARD_REQUIRED ON
)