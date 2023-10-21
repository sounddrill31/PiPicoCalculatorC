/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*https://github.com/raspberrypi/pico-examples/blob/master/hello_world/serial/hello_serial.c*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico-ssd1306/ssd1306.h"
#include "pico-ssd1306/textRenderer/TextRenderer.h"
int main() {
    stdio_init_all();
    i2c_init(I2C_PORT, 1000000); //Use i2c port with baud rate of 1Mhz
//Set pins for I2C operation
    gpio_set_function(I2C_PIN_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_PIN_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_PIN_SDA);
    gpio_pull_up(I2C_PIN_SCL);

//Create a new display object
    pico_ssd1306::SSD1306 display = pico_ssd1306::SSD1306(I2C_PORT, 0x3D, pico_ssd1306::Size::W128xH64);

//create a vertical line on x: 64 y:0-63
    for (int y = 0; y < 64; y++){
        display.setPixel(64, y);
}
    display.sendBuffer(); //Send buffer to device and show on screen
}