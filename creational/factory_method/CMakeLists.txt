project(FactoryMethod LANGUAGES CXX)

add_library(loggerlib INTERFACE logger/logger.h logger/logger_factory.h)
add_executable(logger_factory_test logger/logger_factory_test.cc)
target_link_libraries(logger_factory_test PRIVATE loggerlib)

file(GLOB_RECURSE image_source CONFIGURE_DEPENDS image_reader/*.h)
add_library(imagelib INTERFACE ${image_source})
add_executable(image_reader_factory_test image_reader/image_reader_factory_test.cc)
target_link_libraries(image_reader_factory_test PRIVATE imagelib)