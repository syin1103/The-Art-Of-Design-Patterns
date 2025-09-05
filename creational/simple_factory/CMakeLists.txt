project(SimpleFactory LANGUAGES CXX)

find_package(nlohmann_json REQUIRED)

# Chart
add_library(chartlib INTERFACE chart/chart.h chart/chart_factory.h chart/config_utils.h)
target_link_libraries(chartlib INTERFACE nlohmann_json::nlohmann_json)

add_executable(chart_factory_test chart/chart_factory_test.cc)
target_link_libraries(chart_factory_test PRIVATE chartlib)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/chart/config.json
    ${CMAKE_CURRENT_BINARY_DIR}/config.json
    COPYONLY
)

# Shape
add_library(shapelib INTERFACE shape/shape.h shape/shape_factory.h shape/exception.h)
add_executable(shape_factory_test shape/shape_factory_test.cc)
target_link_libraries(shape_factory_test PRIVATE shapelib)