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
    while (true) {
        int num1,num2,op;
        printf("Enter first number: \n");
        scanf("%d",&num1);
        printf("First number is: %d\n",num1);
        sleep_ms(1000);
        printf("Enter second number: \n");
        scanf("%d",&num2);
        printf("Second number is : %d\n",&num2);
        printf("Enter operation to be performed: Addition, Difference, Multiplication, Division (1,2,3,4, 5 to exit)\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("The sum of the two numbers is: %d\n",num1+num2);
        }
        else if(op==2)
        {
            printf("The difference of the two numbers is: %d\n",num1-num2);
        }
        else
        {
            printf("Exited!");
        }
        
    }
}
