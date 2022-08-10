cmake_minimum_required(VERSION 3.10)

project(Foo)

set(CMAKE_C_COMPILER clang-10)
set(CMAKE_CXX_COMPILER /usr/bin/clang-10)
#set(CMAKE_C_COMPILER clang-10)
#set(CMAKE_CXX_COMPILER clang-10)

message(STATUS "CC from ENV: $ENV{CC}")
set(SERIAL_C_COMPILER ${CMAKE_C_COMPILER})
message(STATUS "SERIAL_C_COMPILER: ${SERIAL_C_COMPILER}")

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  MESSAGE("Clang")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  MESSAGE("GNU")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  MESSAGE("Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  MESSAGE("MSVC")
endif()

# Set the main target name to the project name, can be changed if needed.
set(MAIN_TARGET_NAME ${PROJECT_NAME})

# Create the C++ shared library
add_library(${MAIN_TARGET_NAME}_lib SHARED ${${PROJECT_NAME}_SOURCE_DIR}/src/foo.cpp)
# add_library(${MAIN_TARGET_NAME}_lib SHARED ${${PROJECT_NAME}_SOURCE_DIR}/src/foo.cpp ${${PROJECT_NAME}_SOURCE_DIR}/natvis_file/file.natvis)

# Include directory for the target ${MAIN_TARGET_NAME}_lib
target_include_directories(${MAIN_TARGET_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Target for the firmware example program
add_executable(${MAIN_TARGET_NAME}_executable ${${PROJECT_NAME}_SOURCE_DIR}/src/main.cpp)
# add_executable(${MAIN_TARGET_NAME}_executable ${${PROJECT_NAME}_SOURCE_DIR}/src/main.cpp ${${PROJECT_NAME}_SOURCE_DIR}/natvis_file/file.natvis)

# Set the name of the binary file and the output directory
set_target_properties(${MAIN_TARGET_NAME}_executable PROPERTIES OUTPUT_NAME "foo_example")
set_target_properties(${MAIN_TARGET_NAME}_executable PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set_target_properties(${MAIN_TARGET_NAME}_executable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set_target_properties(${MAIN_TARGET_NAME}_executable PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)

# Set the name of the lib and the output directory
set_target_properties(${MAIN_TARGET_NAME}_lib PROPERTIES RELEASE_OUTPUT_NAME "foo_library")
set_target_properties(${MAIN_TARGET_NAME}_lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)
set_target_properties(${MAIN_TARGET_NAME}_lib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)
set_target_properties(${MAIN_TARGET_NAME}_lib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)

# Link the firmware target to library
target_link_libraries(${MAIN_TARGET_NAME}_executable ${MAIN_TARGET_NAME}_lib)
