# cmake_minimum_required(VERSION 3.13)

add_executable(helloworld
        helloworld.c
        )

# pull in common dependencies
target_link_libraries(helloworld pico_stdlib)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(helloworld)

# add url via pico_set_program_url
example_auto_set_url(helloworld)
#https://github.com/raspberrypi/pico-examples/blob/master/hello_world/serial/CMakeLists.txt