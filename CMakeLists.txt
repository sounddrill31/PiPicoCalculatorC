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
add_executable(helloworld
        helloworld.c
        )

# pull in common dependencies
target_link_libraries(helloworld pico_stdlib)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(helloworld)

# add url via pico_set_program_url
# example_auto_set_url(helloworld)
#https://github.com/raspberrypi/pico-examples/blob/master/hello_world/serial/CMakeLists.txt

