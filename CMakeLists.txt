cmake_minimum_required(VERSION 3.30)
project(vatsimfdps)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable AddressSanitizer for memory leak detection
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

add_subdirectory(shared)
add_subdirectory(core)
add_subdirectory(ingest)
