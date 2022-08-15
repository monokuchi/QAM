
cmake_minimum_required(VERSION 3.13)
project(QAM)

# add_compile_options(-g -O0)

add_executable(qam src/qam.cpp src/qamTX.cpp src/sigproc.cpp)

target_include_directories(qam PUBLIC
                           "${CMAKE_SOURCE_DIR}/src"
                          )
