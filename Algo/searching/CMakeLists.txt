cmake_minimum_required(VERSION 3.0.0)
set(SFML_PATH "F:/External-lib/SFML-2.5.1")
project(dsa VERSION 1.0.0)
include_directories(${SFML_PATH}/include)
link_directories(${SFML_PATH}/lib)
add_executable(dsa src/main.cpp)
target_link_libraries(dsa debug sfml-graphics-d.lib sfml-window-d.lib sfml-system-d.lib)


