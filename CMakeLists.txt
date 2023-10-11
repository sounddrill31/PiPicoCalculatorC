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

add_subdirectory(serial)
# Hardware-specific examples in subdirectories:
add_subdirectory(adc)
add_subdirectory(clocks)
add_subdirectory(cmake)
add_subdirectory(divider)
add_subdirectory(dma)
add_subdirectory(flash)
add_subdirectory(gpio)
add_subdirectory(i2c)
add_subdirectory(interp)
add_subdirectory(multicore)
add_subdirectory(picoboard)
add_subdirectory(pico_w)
add_subdirectory(pio)
add_subdirectory(pwm)
add_subdirectory(reset)
add_subdirectory(rtc)
add_subdirectory(spi)
add_subdirectory(system)
add_subdirectory(timer)
add_subdirectory(uart)
add_subdirectory(usb)
add_subdirectory(watchdog)