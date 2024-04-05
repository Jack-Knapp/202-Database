cmake_minimum_required(VERSION 3.22)
project(RDB)

set(CMAKE_CXX_STANDARD 11)

add_executable(RDB main1.cpp charType.cpp intType.cpp myException.cpp nullType.cpp record.cpp schema.cpp stringType.cpp table.cpp valueType.cpp)
