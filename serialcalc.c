/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"
//if the serial monitor doesn't show anything, blindly type the first number, press enter, second number and press enter
int main() {
    stdio_init_all();
        //#if LIB_PICO_STDIO_USB && !defined( NDEBUG )
        //while ( !stdio_usb_connected() ) { sleep_ms(100); }
        //#endif
    int num1,num2,op;
    //int i=1;
    //char init_message[32];
    int rem;
    //num1=6;
    //num2=7;
    //printf("Program starting\n");
    while (1) {
        //strcpy(init_message, "Enter First and Second Numbers: ");
        printf("Enter First and Second Numbers:\n");
        //puts(init_message);
        scanf("%d %d",&num1,&num2);
        printf("First number is: %d\n",num1);
        printf("Second number is : %d\n",num2);
        //printf("Enter operation to be performed: Addition, Difference, Multiplication, Division  (1,2,3,4, Anything else to exit)\n");
        printf("Enter operation to be performed: Addition, Difference, Multiplication, Division or Remainder (1,2,3,4,5, 6 to exit)\n");
        op=getchar();
        if(op=='1'){
            printf("The sum of the two numbers is: %d\n",num1+num2);
        }
        else if(op=='2'){
            printf("The difference of the two numbers is: %d\n",num1-num2);
        }
        else if(op=='3'){
            printf("The multiplication of the two numbers is: %d\n",num1*num2);
        }
        else if(op=='4'){
            printf("The division of the two numbers is: %d\n",num1/num2);
        }
        else if(op=='5'){
            rem=num1%num2;
            printf("The remainder is: %d\n",rem);
        }
        else{
            printf("Exited!\n");
        }
         
    }
    return 0;  
}
