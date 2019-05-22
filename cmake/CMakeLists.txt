cmake_minimum_required(VERSION 3.8)

project(password_storage)

# Use C++11 standard for compiling
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp
    src/HashTable.cpp src/passwordstorage.cpp)

set(HEADER_FILES include/HashTable.h
    include/passwordstorage.h)

# Add all sources to target
add_executable(password_storage ${SOURCE_FILES} ${HEADER_FILES})

