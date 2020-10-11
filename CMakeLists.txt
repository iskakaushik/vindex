cmake_minimum_required(VERSION 3.10)

project(vindex VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory("third_party/leveldb")

add_executable(vindex.out vindex_main.cpp)

target_link_libraries(vindex.out PUBLIC leveldb)
target_include_directories(vindex.out PUBLIC
                          "${PROJECT_SOURCE_DIR}/third_party/leveldb"
                          )
