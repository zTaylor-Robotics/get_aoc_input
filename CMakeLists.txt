cmake_minimum_required(VERSION 3.26)

project(get_input)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 02)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.h
)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-O3")

# Remove for compiler specific features
set(CMAKE_CXX_EXTENSIONS OFF)
string(APPEND CMAKE_CXX_FLAGS " -Wall")
string(APPEND CMAKE_CXX_FLAGS " -Wbuiltin-macro-redefined")
string(APPEND CMAKE_CXX_FLAGS " -pedantic")
string(APPEND CMAKE_CXX_FLAGS " -Werror")
string(APPEND CMAKE_CXX_FLAGS " -Wextra")

# clangd completion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR})
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(${PROJECT_NAME} PRIVATE
  PROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
  PROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR}
  PROJECT_VERSION_PATCH=${PROJECT_VERSION_PATCH}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)