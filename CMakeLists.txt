 cmake_minimum_required(VERSION 3.13)
# Import the Pico SDK CMake configuration file
include(pico_sdk_import.cmake)
# Set the project name and languages
project(test_project C CXX ASM)
# Set the C and C++ language standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
# Initialize the Pico SDK
pico_sdk_init()
add_executable(blink
        blink.c
        )

# pull in common dependencies
target_link_libraries(blink pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)

# add url via pico_set_program_url
# example_auto_set_url(blink)