cmake_minimum_required(VERSION 3.21)
project(Client)

set(CMAKE_CXX_STANDARD 20)

add_executable(Client main.cpp communicate/ServerInit.h Parse/ParseComm.h)
