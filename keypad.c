#include <stdio.h>
#include <math.h>
#include "hardware/timer.h"
#include "keypad4x4/pico_keypad4x4.h"
#include "pico/stdlib.h"

uint columns[4] = { 11, 10, 9, 8 };
uint rows[4] = { 15, 14, 7, 12 };
char matrix[16] = {
    '1', '2' , '3', 'A',
    '4', '5' , '6', 'B',
    '7', '8' , '9', 'C',
    '*', '0' , '#', 'D'
};
int main() {
    stdio_init_all();
    pico_keypad_init(columns, rows, matrix);

    char key, num1c,num2c;
    int num1,num2;
    while (true) {       
        printf("Enter First Number!\n");
        num1c = pico_keypad_get_key_scanner()-'0';
        num1=(int)num1c;
        printf("Entered Number: %d \n",num1);
        
        printf("Enter Function!\n");
        key = pico_keypad_get_key_scanner();
        //sleep_ms(1000);
        printf("%c",key);

        printf("Enter Second Number!\n");
        num2c= pico_keypad_get_key_scanner()-'0';
        num2= (int)num2c;
        printf("Entered Number: %d \n",num2);
        
        switch(key)
            {
                case 'A':
                    printf("%d + %d = %d\n",num1,num2,num1+num2);
                    break;
                case 'B': 
                    printf("%d - %d = %d\n",num1,num2,num1-num2);
                    break;
                case 'C': 
                    printf("%d * %d = %d\n",num1,num2,num1*num2);
                    break;
                case 'D': 
                    printf("%d / %d = %lf\n",num1,num2,(double)num1/num2);
                    break;
                case '*':
                    printf("%d ^ %d = %d\n",num1,num2,(int)pow(num1,num2));
                    break;
                case '#':
                    printf("%d mod %d = %s\n",num1,num2,num1%num2?"Divisible":"Not Divisible");
                    break;

                default:
                    printf("Invalid!\n");
            }

    }
}

//https://github.com/hhoswaldo/pico-keypad4x4
