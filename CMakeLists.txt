cmake_minimum_required(VERSION 3.28)
project(SimpleFileManagerSystem-C)
set(CMAKE_C_STANDARD 23)
include_directories(include)
file(GLOB_RECURSE SRC_FILES
        src/*.c
)

add_executable(SimpleFileManagerSystem-C ${SRC_FILES}
        include/_stdSFMSC.h
)