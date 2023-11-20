#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "pico-ssd1306/ssd1306.h"
#include "pico-ssd1306/example/image.h"
#include "pico-ssd1306/example/acme_5_outlines_font.h"
#include "pico-ssd1306/example/bubblesstandard_font.h"
#include "pico-ssd1306/example/crackers_font.h"
#include "pico-ssd1306/example/BMSPA_font.h"


const uint8_t num_chars_per_disp[]={7,7,7,5};
const uint8_t *fonts[4]= {acme_font, bubblesstandard_font, crackers_font, BMSPA_font};

#define SLEEPTIME 25

void setup_gpios(void);
void animation(void);

int main() {
    stdio_init_all();

    printf("configuring pins...\n");
    setup_gpios();

    printf("jumping to animation...\n");
    animation();

    return 0;
}


void setup_gpios(void) {
    i2c_init(i2c1, 400000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);
}


void animation(void) {
    const char *words[]= {"SSD1306", "DISPLAY", "DRIVER"};

    ssd1306_t disp;
    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);

    printf("ANIMATION!\n");

    char buf[8];
        for(int i=0; i<sizeof(words)/sizeof(char *); ++i) {
            ssd1306_draw_string(&disp, 8, 24, 2, words[i]);
            ssd1306_show(&disp);
            sleep_ms(800);
            ssd1306_clear(&disp);
        }
        ssd1306_show(&disp);
        sleep_ms(2000);
    }
}
