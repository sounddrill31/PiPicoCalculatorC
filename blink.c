#include "pico/stdlib.h"
#include <stdio.h>
int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    int number,i;
    while (true) {
        printf("Enter number");
        scanf("%d",number);
        while(number>=i){
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        i++;
        }
    }
#endif
return 0;
}