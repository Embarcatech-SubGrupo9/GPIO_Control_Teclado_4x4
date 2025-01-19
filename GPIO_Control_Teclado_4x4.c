#include <stdio.h>
#include "pico/stdlib.h"

// Constantes
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

// Protótipos das funções
void inicializar_pinos();
void controlar_leds(char tecla);
char verificar_tecla();

int main()
{
    stdio_init_all();
    inicializar_pinos();
    uint cont = 0;
    char tecla_temp = '\0';

    while (true)
    {
        char tecla = verificar_tecla();

        // Confere se a tecla continua apertada
        if (tecla_temp == tecla){
            cont++;
        }else{
            tecla_temp = tecla;
            cont = 0;
        }

        // Executa a função se alguma tecla for pressionada por mais de 20 ciclos para contornar o debounce
        if (tecla != '\0' && cont>=20)
        {
            controlar_leds(tecla);
            printf("Tecla pressionada: %c\n", tecla);
        }
    }
}

// Função para verificar qual tecla foi pressionada
char verificar_tecla()
{
    for (int col = 0; col < colunas; col++)
    {
        gpio_put(coluna_pins[col], 1);
        for (int lin = 0; lin < linhas; lin++)
        {
            if (gpio_get(linha_pins[lin]) == 0)
            {
                gpio_put(coluna_pins[col], 0);
                return mapa_tecla[lin][col];
            }
        }
        gpio_put(coluna_pins[col], 0);
    }
    return '\0'; // Retorna '\0' se nenhuma tecla for pressionada
}

// Função para inicializar os pinos
void inicializar_pinos()
{
    for (int i = 0; i < leds; i++)
    {
        gpio_init(led_pin[i]);
        gpio_set_dir(led_pin[i], GPIO_OUT);
        gpio_put(led_pin[i], 0);
    }
    for (int i = 0; i < colunas; i++)
    {
        gpio_init(coluna_pins[i]);
        gpio_set_dir(coluna_pins[i], GPIO_OUT);
        gpio_put(coluna_pins[i], 1);
    }
    for (int i = 0; i < linhas; i++)
    {
        gpio_init(linha_pins[i]);
        gpio_set_dir(linha_pins[i], GPIO_IN);
        gpio_pull_up(linha_pins[i]);
    }
}

// Função para controlar os LEDs
void controlar_leds(char tecla)
{
    for (int i = 0; i < leds; i++)
    {
        gpio_put(led_pin[i], 0);
    }
    switch (tecla)
    {
    case 'A':
        gpio_put(led_pin[0], 1);
        break;
    case 'B':
        gpio_put(led_pin[1], 1);
    case 'C':
        gpio_put(led_pin[2], 1);
    case 'D':
        // Ligar todos os LEDs
        for (int i = 0; i < leds; i++)
        {
            gpio_put(led_pin[i], 1);
        }
    default:
        break;
    }
}
