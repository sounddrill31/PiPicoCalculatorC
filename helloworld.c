/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    //char num1,num2,op;
    int num1,num2,op;
    num1=6;
    num2=7;
    printf("Program starting\n");
    while (1) {
        printf("First number is: %d\n",num1);
        printf("Second number is : %d\n",num2);
        printf("Enter operation to be performed: Addition, Difference, Multiplication, Division (1,2,3,4, 5 to exit)\n");
        op=getchar();
        //scanf("%d",&op);
        //op = getchar();
        if(op=='1'){
            //printf("The sum of the two numbers is: %d\n",result_num1+result_num2);
            printf("The sum of the two numbers is: %d\n",num1+num2);
        }
        else if(op=='2'){
            //printf("The difference of the two numbers is: %d\n",result_num1-result_num2);
            printf("The difference of the two numbers is: %d\n",num1-num2);
        }
        else if(op=='3'){
            //printf("The multiplication of the two numbers is: %d\n",result_num1*result_num2);
            printf("The multiplication of the two numbers is: %d\n",num1*num2);
        }
        else if(op=='4'){
            //printf("The division of the two numbers is: %d\n",result_num2/result_num2);
            printf("The division of the two numbers is: %d\n",num2/num2);
        }
        else{
            printf("Exited!\n");
        }
        //sleep_ms(100);
        return 0;   
    }
}
