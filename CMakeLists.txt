cmake_minimum_required(VERSION 4.1)
project(engineman)

set(CMAKE_CXX_STANDARD 14)

add_executable(engineman
        src/main.cpp
        src/fix/encoding/tagvalue/parser.cpp
)

target_include_directories(engineman PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/fix/encoding/tagvalue)