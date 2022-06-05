cmake_minimum_required(VERSION 3.21)
project(basic)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD 14)

#返回值优化
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
#产生中间文件
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdump-tree-all")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdump-tree-all")
#SET($CFLAGS "${CFLAGS} -fdump-tree-all")

add_executable(basic main.cpp test1.cpp test2.cpp
        modern-cpp/1-1.cpp modern-cpp/2-4.cpp modern-cpp/4-1.cpp modern-cpp/6-1.cpp
        modern-cpp/6-2.cpp modern-cpp/6-3.cpp modern-cpp/6-4.cpp modern-cpp/6-5.cpp modern-cpp/6-6.cpp modern-cpp/7-1.cpp modern-cpp/9-1.cpp modern-cpp/9-2.cpp modern-cpp/11-1.cpp modern-cpp/12-1.cpp modern-cpp/12-2.cpp modern-cpp/12-3.cpp modern-cpp/13-1.cpp modern-cpp/15-1.cpp modern-cpp/20-1.cpp modern-cpp/20-2.cpp modern-cpp/21-1.cpp)
