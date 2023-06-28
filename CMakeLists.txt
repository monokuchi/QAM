
cmake_minimum_required(VERSION 3.13)
project(QAM)

# add_compile_options(-g -O0)

set(COMMON_FILES src/tools/qamUtil.cpp src/tools/sigproc.cpp)

#############################################################

add_executable(TX src/tx/TX.cpp src/tx/qamTX.cpp src/tx/radioTX.cpp ${COMMON_FILES})

target_include_directories(TX PUBLIC
                           "${CMAKE_SOURCE_DIR}/src"
                          )

                          
add_executable(RX src/rx/RX.cpp src/rx/qamRX.cpp src/rx/radioRX.cpp ${COMMON_FILES})

target_include_directories(RX PUBLIC
                           "${CMAKE_SOURCE_DIR}/src"
                          )
