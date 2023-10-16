/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"

void main() {
    stdio_init_all();
    int num1,num2,op;
    while (true) {
        //sleep_ms(100);
        printf("Enter first number: \n");
        num1=getchar();
        //scanf("%d",&num1);
        printf("First number is: %d\n",num1);
        printf("Enter second number: \n");
        num2=getchar();
        //scanf("%d",&num2);
        printf("Second number is : %d\n",&num2);
        printf("Enter operation to be performed: Addition, Difference, Multiplication, Division (1,2,3,4, 5 to exit)\n");
        op=getchar();
        //scanf("%d",&op);
        if(op==1)
        {
            printf("The sum of the two numbers is: %d\n",num1+num2);
        }
        else if(op==2)
        {
            printf("The difference of the two numbers is: %d\n",num1-num2);
        }
        else if(op==3)
        {
            printf("The multiplication of the two numbers is: %d\n",num1*num2);
        }
        else if(op==4)
        {
            printf("The division of the two numbers is: %d\n",num1/num2);
        }
        else
        {
            printf("Exited!");
        }
        sleep_ms(100);   
    }
}
