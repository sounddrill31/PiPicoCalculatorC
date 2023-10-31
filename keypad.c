#include <stdio.h>
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
        //printf("Key pressed: %c\n", key);
        
        printf("Enter First Number!\n");
        num1c=pico_keypad_get_key();
        num1=atoi(num1c);
        busy_wait_us(20000000);
        printf("Enter Second Number!\n");
        num2c=pico_keypad_get_key();
        num2=atoi(num2c);
        busy_wait_us(20000000);
        

        printf("Enter Function!\n");
        key = pico_keypad_get_key();
        sleep_ms(1000);

        busy_wait_us(20000000);
        switch(key)
            {
                case 'A':
                    printf("%d + %d = %d",num1,num2,num1+num2);
                    break;
                case 'B': 
                    //printf("Enter First Number!\n");
                    //num1c=pico_keypad_get_key();
                    //num1=atoi(num1c);
                    //printf("Enter Second Number!\n");
                    //num2c=pico_keypad_get_key();
                    //num2=atoi(num2c);
                    printf("%d - %d = %d",num1,num2,num1-num2);
                    break;
                case 'C': 
                    //printf("Enter First Number!\n");
                    //num1c=pico_keypad_get_key();
                    //num1=atoi(num1c);
                    //printf("Enter Second Number!\n");
                    //num2c=pico_keypad_get_key();
                    //num2=atoi(num2c);
                    printf("%d * %d = %d",num1,num2,num1*num2);
                    break;
                case 'D': 
                    //printf("Enter First Number!\n");
                    //num1c=pico_keypad_get_key();
                    //num1=atoi(num1c);
                    //printf("Enter Second Number!\n");
                    //num2c=pico_keypad_get_key();
                    //num2=atoi(num2c);
                    printf("%d / %d = %d",num1,num2,num1/num2);
                    break;
                default:
                    printf("Invalid!\n");
            }

    }
}

//https://github.com/hhoswaldo/pico-keypad4x4
