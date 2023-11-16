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

int scanner()
{
        int time=1;
        int endCheckingTime=100000000;    
        char key;
        printf("Enter key\n");
        do {     

        key = pico_keypad_get_key(); time++; 
        }while(time < endCheckingTime && key == NULL);
        return key;
}

int main() {
    stdio_init_all();
    pico_keypad_init(columns, rows, matrix);

    char key, num1c,num2c;
    int num1,num2;
    while (true) {
        busy_wait_us(20000000);        
        printf("Enter First Number!\n");
        num1c = scanner();
        num1=atoi(num1c);
        printf("Entered number is: %d \n",num1);
        busy_wait_us(2000000);
        printf("Enter Second Number!\n");
        num2c= scanner();
        num2=atoi(num2c);
        busy_wait_us(2000000);
        printf("Entered number is: %d \n",num2);
        

        printf("Enter Function!\n");
        key = scanner();
        //sleep_ms(1000);

        busy_wait_us(20000000);
        switch(key)
            {
                case 'A':
                    printf("%d + %d = %d",num1,num2,num1+num2);
                    break;
                case 'B': 
                    printf("%d - %d = %d",num1,num2,num1-num2);
                    break;
                case 'C': 
                    printf("%d * %d = %d",num1,num2,num1*num2);
                    break;
                case 'D': 
                    printf("%d / %d = %d",num1,num2,num1/num2);
                    break;
                default:
                    printf("Invalid!\n");
            }

    }
}

//https://github.com/hhoswaldo/pico-keypad4x4
