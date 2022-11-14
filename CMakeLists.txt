cmake_minimum_required(VERSION 3.24.3)
project(math_problems
    VERSION 0.1.0
    DESCRIPTION "Math problems"
    LANGUAGES CXX
)
add_executable(${PROJECT_NAME} src/experiments/vector_test.cpp)
add_library(
    math_library src/generic_defs/vector.cpp 
    src/domains/linear_algebra/almat.cpp 
    src/domains/linear_algebra/alvec.cpp)

target_include_directories(math_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)