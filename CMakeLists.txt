cmake_minimum_required(VERSION 4.0)
project(advent-of-code-2026 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/experimental:module)
    add_compile_options(/std:c++latest)
endif()

# Find external dependencies
find_package(glm CONFIG REQUIRED)

# Add utils library CMakeLists
add_subdirectory(utils)

# Main executable (launch target 1)
add_executable(aoc
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(aoc
    PUBLIC
        ${PROJECT_SOURCE_DIR}/public
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(aoc
    PUBLIC
        glm::glm
    PRIVATE
        aoc_modules
)

# Test executable (launch target 2, only built during local development)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()

# Install engine assets so cmake --install and Conan packaging both work
install(DIRECTORY ${PROJECT_SOURCE_DIR}/input/ DESTINATION input)
