# CMakeList.txt : CMake project for ceng477hw1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ceng477hw1")

# Add source to this project's executable.
add_executable (raytracer "parser.cpp" "parser.h" "ppm.cpp" "ppm.h" "raytracer.cpp" "tinyxml2.cpp" "tinyxml2.h" "Algebra.h" "Algebra.cpp" "Ray.h" "Ray.cpp" "World.cpp")

# TODO: Add tests and install targets if needed.
