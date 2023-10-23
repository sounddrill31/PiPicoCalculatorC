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
add_executable(oled
        oled.c
        )

# pull in common dependencies
target_link_libraries(oled 
        pico_stdlib
        hardware_timer
        )

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(oled)

# add url via pico_set_program_url
# example_auto_set_url(oled)
#https://github.com/raspberrypi/pico-examples/blob/master/hello_world/serial/CMakeLists.txt

# Enable USB stdio for the "test" target (used for serial communication)
pico_enable_stdio_usb(oled 1)

# Disable UART stdio for the "test" target
pico_enable_stdio_uart(oled 0)
#https://www.exasub.com/development-kit/raspberry-pi-pico/how-to-use-c-sdk-to-create-uf2-file-which-interface-ultrasonic-sensor-with-raspberry-pi-pico/

add_library(oledlib STATIC ss_oled/ss_oled.c)
target_link_libraries(oled
    oledlib
)
target_link_libraries(oledlib
    pico_stdlib
    hardware_i2c
    string
)