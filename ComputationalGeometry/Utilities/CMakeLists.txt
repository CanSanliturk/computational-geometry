# Utilities/CMakeLists.txt

file(GLOB_RECURSE UTILITIES_SOURCE_FILES "src/*.cpp")
include_directories(include)

add_library(UtilitiesLib ${UTILITIES_SOURCE_FILES})

target_include_directories(UtilitiesLib PUBLIC include)

# Link Boost libraries if required
target_link_libraries(UtilitiesLib PUBLIC)
