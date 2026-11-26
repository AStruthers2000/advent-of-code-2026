add_executable(aoc_tests
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Once CppUTest comes in via Conan:
# find_package(CppUTest CONFIG REQUIRED)
# target_link_libraries(aoc_tests PRIVATE CppUTest::CppUTest)
