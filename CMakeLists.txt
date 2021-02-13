cmake_minimum_required(VERSION 3.8.2)
# Include cmake modules
list(APPEND CMAKE_MODULE_PATH 
"${CMAKE_CURRENT_SOURCE_DIR}/CMake")

project(doctesttest)

# Compile options
include(CMake/CompileOptions.cmake)
add_compile_options(-std=c++14)

add_library(calc 
    src/calc.cpp
)

target_include_directories(calc
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)


add_executable(main
    src/main.cpp
)


target_link_libraries(main
    calc
)

# Code coverage - Debug only
# NOTE: Code coverage results with an optimized (non-Debug) build may be misleading
option(BUILD_COVERAGE "Build code coverage" OFF)
if (CMAKE_BUILD_TYPE MATCHES Debug AND CMAKE_COMPILER_IS_GNUCXX AND BUILD_COVERAGE)
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage main coverage)
endif()