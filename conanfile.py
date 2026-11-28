from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class AdventOfCode2026Conan(ConanFile):
    name = "advent-of-code-2026"
    author = "AStruthers2000"
    description = ""

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    export_sources = "CMakeLists.txt", "src/*", "public/*", "input/*", "cmake/*"


    def requirements(self):
        self.requires("glm/1.0.1", transitive_headers=True)
        self.requires("ctre/3.11.0")


    def layout(self):
        cmake_layout(self)


    def build(self):
        cmake = CMake(self)
        cmake.configure(variables={"BUILD_TESTING": "OFF"})
        cmake.build()

