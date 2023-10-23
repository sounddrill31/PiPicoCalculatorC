/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*https://github.com/raspberrypi/pico-examples/blob/master/hello_world/serial/hello_serial.c*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "ss_oled/ss_oled.h"
int main() {
    stdio_init_all();
    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}