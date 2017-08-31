cmake_minimum_required(VERSION 2.8)

project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -std=c++14")

# headers
set(HEADER_DIR "include")
set(MY_LIB_DIR "/home/xudong/dev/MyLib/cpplib")
include_directories(${HEADER_DIR} ${MY_LIB_DIR})
file(GLOB HEADERS "${MY_LIB_DIR}/*.h" "${HEADER_DIR}/*.h")
message("headers: " ${HEADERS})

# source file
#set(SRC_LIST 321_Create_Maximum_Number.cpp)
file(GLOB SRC_LIST "321_*.cpp")
message("source file: " ${SRC_LIST})

add_executable(main ${HEADERS} ${SRC_LIST})
