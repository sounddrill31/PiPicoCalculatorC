#include "pico/stdlib.h"
#include "pico-ssd1306/ssd1306.h"
#include "pico-ssd1306/textRenderer/TextRenderer.h"
#include "hardware/i2c.h"

// Use the namespace for convenience
//using namespace pico_ssd1306;

int main(){i2c_init(I2C_PORT, 1000000); //Use i2c port with baud rate of 1Mhz
//Set pins for I2C operation
gpio_set_function(I2C_PIN_SDA, GPIO_FUNC_I2C);
gpio_set_function(I2C_PIN_SCL, GPIO_FUNC_I2C);
gpio_pull_up(I2C_PIN_SDA);
gpio_pull_up(I2C_PIN_SCL);

//Create a new display object
pico_ssd1306::SSD1306 display = pico_ssd1306::SSD1306(I2C_PORT, 0x3D, pico_ssd1306::Size::W128xH64);

    // Here we rotate the display by 180 degrees, so that it's not upside down from my perspective
    // If your screen is upside down try setting it to 1 or 0
    display.setOrientation(0);

    for (int y = 0; y < 64; y++){
        drawText(&display, font_12x16, "TEST text", 0 ,0);
        }
    //Send buffer to device and show on screen
    // Send buffer to the display
    display.sendBuffer();
}