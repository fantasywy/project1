cmake_minimum_required(VERSION 3.26.0)
project(project1 VERSION 0.1.0 LANGUAGES C)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.c)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(app)

target_sources(app PRIVATE ${SRC})
target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/include)