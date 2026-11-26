cmake_minimum_required(VERSION 4.0)

# Must be set before project() so the toolchain can be probed for `import std` support
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
set(CMAKE_CXX_MODULE_STD ON)

project(advent-of-code-2026 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
