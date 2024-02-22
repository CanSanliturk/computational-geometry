# Core/CMakeLists.txt

file(GLOB_RECURSE CORE_SOURCE_FILES "src/*.cpp")

add_library(CoreLib ${CORE_SOURCE_FILES})

# Include directories

target_include_directories(CoreLib PUBLIC include 
    ${PROJECT_SOURCE_DIR}/Utilities/include
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(CoreLib PUBLIC UtilitiesLib)
