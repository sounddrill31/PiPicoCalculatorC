#include <stdio.h>
#include "hardware/timer.h"
#include "keypad4x4/pico_keypad4x4.h"
#include "pico/stdlib.h"
#include "pico/time.h"

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
    char key;
    while (true) {
        printf("Enter key\n");
        key = pico_keypad_get_key_scanner();
        printf("Key pressed: %c\n", key);
        busy_wait_us(500000);
    }
    busy_wait_us(500000);
}

//https://github.com/hhoswaldo/pico-keypad4x4
//https://github.com/sounddrill31/pico-keypad4x4-blocking