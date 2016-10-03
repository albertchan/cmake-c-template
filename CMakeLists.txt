cmake_minimum_required(VERSION 3.5)

# Configuration
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

##########################################################################
# Find ZeroMQ headers and libraries
# => ZeroMQ_FOUND   		    : System has ZeroMQ libs/headers
# => ZeroMQ_INCLUDE_DIR		    : Location of ZeroMQ headers
# => ZeroMQ_LIBRARIES	        : ZeroMQ libraries
find_package(ZeroMQ)

if(NOT ZeroMQ_FOUND)
    message(FATAL_ERROR "ZeroMQ headers required to build project")
endif()

add_subdirectory(src/server)
add_subdirectory(src/client)