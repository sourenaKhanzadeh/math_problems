cmake_minimum_required(VERSION 3.24.3)
project(math_problems
    VERSION 0.1.0
    DESCRIPTION "Math problems"
    LANGUAGES CXX
)
add_subdirectory(external/SDL)
add_subdirectory(external/SDL_TTF)

add_executable(${PROJECT_NAME} src/experiments/vector_test.cpp)

add_library(
    math_library STATIC 
    src/utils/graphics.cpp
    src/generic_defs/vector.cpp 
    src/domains/linear_algebra/almat.cpp 
    src/domains/linear_algebra/alvec.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL/include
    ${CMAKE_SOURCE_DIR}/external/SDL_TTF/
)
    
target_include_directories(${PROJECT_NAME} 
PUBLIC ${CMAKE_SOURCE_DIR}/include
PUBLIC ${CMAKE_SOURCE_DIR}/external/SDL/include
PUBLIC ${CMAKE_SOURCE_DIR}/external/SDL_TTF/
)
    
target_link_libraries(${PROJECT_NAME} math_library SDL2 SDL2_ttf)
