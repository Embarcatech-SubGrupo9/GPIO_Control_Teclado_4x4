#include <stdio.h>
#include "pico/stdlib.h"

const int colunas = 4;
const int linhas = 4;
const int leds = 3;

const uint8_t led_pin[] = {11, 12, 13};
const uint8_t coluna_pins[] = {4, 3, 2, 28};
const uint8_t linha_pins[] = {8, 7, 6, 5};
const uint8_t buzzer_pin = 10;

const char mapa_tecla[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

int main()
{
    stdio_init_all();
    while (true)
    {
        printf("Hello, Wokwi!\n");
        sleep_ms(250);
    }
}