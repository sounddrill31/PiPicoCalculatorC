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
    int num1,num2;
    char ch1,ch2, op;
    while (1) {
        //sleep_ms(100);
        printf("Enter first number: \n");
        //num1=getchar();
        scanf("%d",&num1);
    //int num1_int = num1 - '0';
    //int result_num1 = num1_int + 1;
        ch1 = getchar();
                while (ch1 != '\n') { // Loop until newline
                    num1 = num1 * 10 + (ch1 - '0'); // Convert the character to a digit and add it to the number
                    ch1 = getchar(); // Read the next character
                }
        printf("First number is: %d\n",num1);
        printf("Enter second number: \n");
        ch2=getchar();
                while (ch2 != '\n') { // Loop until newline
                    num2 = num2 * 10 + (ch2 - '0'); // Convert the character to a digit and add it to the number
                    ch2 = getchar(); // Read the next character
                }
        //scanf("%d",&num2);
    //int num2_int = num2 - '0';
    //int result_num2 = num2_int + 1;    
        //num2 = getchar();
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
