# Tests/CMakeLists.txt

enable_testing()

# Add the source files
file(GLOB_RECURSE TEST_SOURCE_FILES "src/*.cpp")

# Add the executable
add_executable(ComputationalGeometryTests ${TEST_SOURCE_FILES})

# Find boost library
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Include the Utilities and Core directories
target_include_directories(ComputationalGeometryTests PUBLIC 
    ${CMAKE_SOURCE_DIR}/../Utilities/include
    ${CMAKE_SOURCE_DIR}/../Core/include
    include
    ${Boost_INCLUDE_DIRS}
)

# Link Boost libraries for testing
target_link_libraries(ComputationalGeometryTests PRIVATE UtilitiesLib CoreLib Boost::unit_test_framework)

# Add a test
add_test(
    NAME ComputationalGeometryTests
    COMMAND ComputationalGeometryTests
)
