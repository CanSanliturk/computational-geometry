# Core/CMakeLists.txt

file(GLOB_RECURSE CORE_SOURCE_FILES "src/*.cpp")

add_library(CoreLib ${CORE_SOURCE_FILES})

# Include the Utilities directory
target_include_directories(CoreLib PUBLIC include ${CMAKE_SOURCE_DIR}/../Utilities/include)

# Link Boost libraries if required
find_package(Boost 1.83.0 REQUIRED)
target_link_libraries(CoreLib PUBLIC UtilitiesLib Boost::boost)
