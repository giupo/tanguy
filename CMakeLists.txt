cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
set(EXECUTABLE tanguy)

project(${EXECUTABLE})

file(GLOB SOURCES "src/*")

add_executable(${EXECUTABLE} ${SOURCES})
