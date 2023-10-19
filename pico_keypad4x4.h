/*
|| @file pico_keypad4x4.h
|| @version 0.2
|| @author Oswaldo Hernandez, Owen Jauregui
|| @contact oswahdez00@gmail.com
||
|| @description
|| | This library provides a simple interface for using a 4x4 matrix
|| | keypad with the Raspberry Pi Pico.
*/

#ifndef PICO_KEYPAD4X4_H
#define PICO_KEYPAD4X4_H

#include "pico/stdlib.h"
#include "hardware/timer.h"

void pico_keypad_init(uint columns[4], uint rows[4], char matrix_values[16]);

char pico_keypad_get_key(void);

void pico_keypad_irq_enable(bool enable, gpio_irq_callback_t callback);

#endif

