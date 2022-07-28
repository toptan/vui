cmake_minimum_required(VERSION 3.22)
project(vui)

# Set some variables that can be overridden
if (NOT AMIGA_SHARED_DIR)
    set(AMIGA_SHARED_DIR "/home/toptan/Documents/FS-UAE/Hard Drives/Shared")
endif ()

# Set standard to C++17 without extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Check our build type and set debug macro
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

# Add our binary
add_executable(vui main.cpp
        lib/src/VApplication.cpp
        )

target_include_directories(vui PUBLIC ${PROJECT_SOURCE_DIR}/lib/include)

# Copy produced binary to shared directory with Amiga
add_custom_command(TARGET vui
        POST_BUILD
        COMMAND cp ARGS ${CMAKE_BINARY_DIR}/vui ${AMIGA_SHARED_DIR}
        )