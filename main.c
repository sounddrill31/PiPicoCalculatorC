#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include <math.h>
#include "keypad4x4/pico_keypad4x4.h"


//initializing the matrix keypad
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
    char str[50];
    int num1,num2;
    #ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);
    // This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    lcd_init();
       static char *message[] =
            {
                    "1st Number", "2nd Number",
                    "Operation"
            }; //cycles through these messages

    while (1) {
        for (int m = 0; m < sizeof(message) / sizeof(message[0]); m += MAX_LINES) {
            for (int line = 0; line < MAX_LINES; line++) {
                lcd_set_cursor(line, (MAX_CHARS / 2) - strlen(message[m + line]) / 2);
                lcd_string(message[m + line]);
                if(m==1){
                            num1c = pico_keypad_get_key_scanner()-'0';
                            num1=(int)num1c;
                            sprintf(str, "%d", num1);
                            //lcd_set_cursor(line,2);
                            //lcd_clear();
                            lcd_string(str);
                            lcd_clear();
                    continue; //executed if program is checking for the first number. 
                }
                else if(m==2){
                            num2c = pico_keypad_get_key_scanner()-'0';
                            num2=(int)num2c;
                            sprintf(str, "%d", num2);
                            //lcd_set_cursor(line,2);
                            //lcd_clear();
                            lcd_string(str); //executed if program is checking for the second number.
                            lcd_clear();
                    continue;
                }
                else if(m==3){ //Takes inputs and does operations.
                            key = pico_keypad_get_key_scanner();
                            switch(key)
                            {
                case 'A':
                    //tostring(str, num1+num2);
                    sprintf(str, "%d + %d = %d", num1,num2,num1+num2);
                    //lcd_clear();
                    lcd_string( str);
                    lcd_clear();
                    break;
                case 'B': 
                    //tostring(str, num1-num2);
                    sprintf(str, "%d - %d = %d", num1,num2,num1-num2);
                    //lcd_clear();
                    lcd_string( str);
                    lcd_clear();
                    break;
                case 'C': 
                    //tostring(str, num1*num2);
                    sprintf(str, "%d * %d = %d", num1,num2,num1*num2);
                    //lcd_clear();
                    lcd_string( str);
                    lcd_clear();
                    break;
                case 'D': 
                    //tostring(str, num1/num2);
                    sprintf(str, "%d / %d = %d", num1,num2,num1/num2);
                    //lcd_clear();
                    lcd_string( str);
                    lcd_clear();
                    break;
                case '*':
                    //tostring(str, (int)pow(num1,num2));
                    sprintf(str, "%d ^ %d = %lf", num1,num2,pow(num1,num2));
                    //lcd_clear();
                    lcd_string( str);
                    lcd_clear();
                    break;
                case '#':
                    //lcd_clear();
                    lcd_string(num1%num2==0?"Divisible":"Not Divisible"); 
                    lcd_clear();
                    break;

                default:
                    break;                                
                            }

                }
                else { break; }
            }
            sleep_ms(2000);
            lcd_clear();
        }
    }
    #endif
    return 0;
}