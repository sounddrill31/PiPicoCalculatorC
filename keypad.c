#include <stdio.h>
#include "hardware/timer.h"
#include "keypad4x4/pico_keypad4x4.h"
#include "pico/stdlib.h"
#include "pico/time.h"
//void gpio_callback(uint gpio, uint32_t event);

uint columns[4] = { 18, 19, 20, 21 };
uint rows[4] = { 10, 11, 12, 15 };
char matrix[16] = {
    '1', '2' , '3', 'A',
    '4', '5' , '6', 'B',
    '7', '8' , '9', 'C',
    '*', '0' , '#', 'D'
};

int main() {
    int time=1;
    int endCheckingTime=100000000;
    stdio_init_all();
    pico_keypad_init(columns, rows, matrix);
    //pico_keypad_irq_enable(true, gpio_callback);

    char key;
    while (true) {
        printf("Enter key\n");
        do { 
            key = pico_keypad_get_key(); time++; 
        }while(time < endCheckingTime && key == NULL);

/*      key = pico_keypad_get_key();
        change_state(key);
        keypadWait = add_alarm_in_ms(1000, alarm_callback, NULL, true);
        keypad_irq_enable(false, gpio_callback);  */
        printf("Key pressed: %c\n", key);
    }
}

//https://github.com/hhoswaldo/pico-keypad4x4
