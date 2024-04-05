cmake_minimum_required(VERSION 3.21)
project(basic)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD 14)

#生成32位程序：
set(CMAKE_CXX_FLAGS -m32)
set(CMAKE_C_FLAGS -m32)

#64位：
#set(CMAKE_CXX_FLAGS -m64)
#set(CMAKE_C_FLAGS -m64)

#返回值优化
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
#产生中间文件
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdump-tree-all")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdump-tree-all")
#SET($CFLAGS "${CFLAGS} -fdump-tree-all")

add_executable(basic main.cpp test1.cpp test2.cpp
        modern-cpp/1-1.cpp modern-cpp/2-4.cpp modern-cpp/4-1.cpp modern-cpp/6-1.cpp
        modern-cpp/6-2.cpp modern-cpp/6-3.cpp modern-cpp/6-4.cpp modern-cpp/6-5.cpp
        modern-cpp/6-6.cpp modern-cpp/7-1.cpp modern-cpp/9-1.cpp modern-cpp/9-2.cpp
        modern-cpp/11-1.cpp modern-cpp/12-1.cpp modern-cpp/12-2.cpp modern-cpp/12-3.cpp
        modern-cpp/13-1.cpp modern-cpp/15-1.cpp modern-cpp/20-1.cpp modern-cpp/20-2.cpp
        modern-cpp/21-1.cpp modern-cpp/24-1.cpp modern-cpp/24-2.cpp modern-cpp/25-1.cpp
        modern-cpp/27-1.cpp modern-cpp/27-2.cpp modern-cpp/29-1.cpp modern-cpp/30-1.cpp
        modern-cpp/30-2.cpp modern-cpp/31-1.cpp modern-cpp/31-2.cpp modern-cpp/31-3.cpp
        modern-cpp/34-1.cpp modern-cpp/34-2.cpp test3.cpp test4.cpp test5.cpp
        main.c)
