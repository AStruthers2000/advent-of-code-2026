cmake_minimum_required(VERSION 3.28)
project(advent-of-code-2026 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find external dependencies
find_package(glm CONFIG REQUIRED)

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
)

# Test executable (launch target 2, only built during local development)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()

# Install engine assets so cmake --install and Conan packaging both work
install(DIRECTORY ${PROJECT_SOURCE_DIR}/input/ DESTINATION input)
