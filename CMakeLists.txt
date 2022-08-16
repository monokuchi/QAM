
cmake_minimum_required(VERSION 3.13)
project(QAM)

# add_compile_options(-g -O0)

set(COMMON_FILES src/sigproc.cpp src/qamUtil.cpp)

#############################################################

add_executable(TX src/TX.cpp src/qamTX.cpp ${COMMON_FILES})

target_include_directories(TX PUBLIC
                           "${CMAKE_SOURCE_DIR}/src"
                          )

                          
add_executable(RX src/RX.cpp src/qamRX.cpp ${COMMON_FILES})

target_include_directories(RX PUBLIC
                           "${CMAKE_SOURCE_DIR}/src"
                          )
