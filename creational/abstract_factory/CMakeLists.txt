project(AbstractFactory LANGUAGES CXX)

file(GLOB_RECURSE skin_srcs CONFIGURE_DEPENDS skin/*.h)
add_library(skinlib INTERFACE ${skin_srcs})
add_executable(skin_factory_test skin/skin_factory_test.cc)
target_link_libraries(skin_factory_test PRIVATE skinlib)


file(GLOB_RECURSE game_srcs CONFIGURE_DEPENDS game/*.h)
add_library(gamelib INTERFACE ${game_srcs})
add_executable(game_factory_test game/game_factory_test.cc)
target_link_libraries(game_factory_test PRIVATE gamelib)