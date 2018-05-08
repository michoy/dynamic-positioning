cmake_minimum_required(VERSION 3.10)
project(datametoder C)
set(CMAKE_C_STANDARD 11)

include_directories("C:/Program Files/Phidgets/Phidget22")
link_directories("C:/Program Files/Phidgets/Phidget22/x86")
find_library(phidget22 "C:/Program Files/Phidgets/Phidget22/phidget22.h")

set(EXECUTABLES src/main.c src/VoltageInput.c src/RCServo.c src/PhidgetHelperFunctions.c src/animate.c src/animate.h)

set(HEADERS src/VoltageInput.h src/RCServo.h src/PhidgetHelperFunctions.h src/animate.c src/animate.h)

add_executable(datametoder ${EXECUTABLES} ${HEADERS})
target_link_libraries(datametoder phidget22)
target_link_libraries(datametoder m)
