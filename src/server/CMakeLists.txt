cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME cmake_c_template)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

#project(cmake_c_template)
project(${PROJECT_NAME})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# Include paths
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include/sds)

# Assign the include directories
include_directories(${INCLUDE_DIRS})

# Find library sources
file(GLOB_RECURSE LIB_SOURCES ${CMAKE_SOURCE_DIR}/include/*/*.c)

# Build static/shared library
add_library(${PROJECT_NAME}_lib STATIC ${LIB_SOURCES})

# Install library
install(TARGETS ${PROJECT_NAME}_lib DESTINATION lib)

# Install library headers
file(GLOB_RECURSE LIB_HEADERS ${CMAKE_SOURCE_DIR}/include/*/*.h)
install(FILES ${LIB_HEADERS} DESTINATION ${CMAKE_SOURCE_DIR}/include)

set(SOURCE_FILES main.c)
add_executable(cmake_c_template ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)
set_target_properties(${PROJECT_NAME}_lib PROPERTIES LINKER_LANGUAGE C)