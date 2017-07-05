cmake_minimum_required(VERSION 3.6.0)
project (Classifier)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/local/lib/cmake/)

#WiringPi Library
find_package(WiringPi REQUIRED)
find_package(Threads REQUIRED) 
include_directories(${WIRINGPI_INCLUDE_DIRS}) 
set(EXTR_LIBS ${EXTR_LIBS} ${WIRINGPI_LIBRARIES})

#Pre-Setup for compilation of Main Target
add_definitions(-Wall -g -std=c++11)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")

#Main Target
add_executable(demo ${SOURCES})
target_link_libraries(demo ${EXTR_LIBS})
