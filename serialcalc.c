/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*https://github.com/raspberrypi/pico-examples/blob/master/hello_world/serial/hello_serial.c*/
#include <stdio.h>
#include "pico/stdlib.h"

void main() {
    stdio_init_all();
    int num1,num2;
    clrscr();
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("First number is: %d",num1);
    sleep_ms(1000);
    //while (true) {
    //    printf("Hello, world!\n");
    //    sleep_ms(1000);
    //}
}