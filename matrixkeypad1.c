#include <stdio.h>
//#include "hardware/timer.h"
#include "keypad4x4/pico_keypad4x4.h"
#include "pico/stdlib.h"

uint columns[4] = { 18, 19, 20, 21 };
uint rows[4] = { 10, 11, 12, 13 };
char matrix[16] = {
    '1', '2' , '3', 'A',
    '4', '5' , '6', 'B',
    '7', '8' , '9', 'C',
    '*', '0' , '#', 'D'
};

int main() {
    stdio_init_all();
    pico_keypad_init(columns, rows, matrix);
    char key;
    while (true) {
        key = pico_keypad_get_key();
        printf("Key pressed: %c\n", key);
        //busy_wait_us(500000);
    }
}

//https://github.com/hhoswaldo/pico-keypad4x4