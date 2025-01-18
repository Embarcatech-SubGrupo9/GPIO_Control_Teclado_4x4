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

void inicializar_pinos() {

    for (int i = 0; i < leds; i++) {
        gpio_init(led_pin[i]);
        gpio_set_dir(led_pin[i], GPIO_OUT);
        gpio_put(led_pin[i], 0);
    }
    for (int i = 0; i < colunas; i++) {
        gpio_init(coluna_pins[i]);
        gpio_set_dir(coluna_pins[i], GPIO_OUT);
        gpio_put(coluna_pins[i], 1);
    }
    for (int i = 0; i < linhas; i++) {
        gpio_init(linha_pins[i]);
        gpio_set_dir(linha_pins[i], GPIO_IN);
        gpio_pull_up(linha_pins[i]);
    }
}

void controlar_leds(char tecla) {
    for (int i = 0; i < leds; i++) {
        gpio_put(led_pin[i],0);
    }
    if (tecla == 'A') {
        gpio_put(led_pin[0],1);
    } else if (tecla == 'B') {
        gpio_put(led_pin[1],1);  
    } else if (tecla == 'C') {
        gpio_put(led_pin[2],1 );
    } else if (tecla == 'D') { // função para ligar todos os leds
        for (int i = 0; i< leds; i++) {
            gpio_put(led_pin[i],1);
        }
    }
}

int main()
{
    stdio_init_all();
    while (true)
    {
        if (tecla) {
            controlar_leds(tecla);
            printf("Tecla pressionada: %c\n", tecla);
            controlar_leds(tecla);
            sleep_ms(100);
        }
    }
}