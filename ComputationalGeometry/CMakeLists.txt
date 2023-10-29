cmake_minimum_required(VERSION 3.1)
project(ComputationalGeometry)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set build type (default to Release if not specified)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add subdirectories
add_subdirectory(Utilities)
add_subdirectory(Core)
add_subdirectory(Tests)
