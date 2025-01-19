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
void tocar_buzzer(uint16_t FREGUENCIA, uint16_t DURACAO);

int main()
{
    uint8_t i = 0;
    uint16_t freguencia = 1000; // Exemplo: 1kHz
    uint16_t duracao = 500;     // Exemplo: 500ms

    inicializar_pinos();
    stdio_init_all();

    while (true)
    {
        char operado = verificar_tecla();
        switch (operado)
        {
        case '#':
            printf("Entrou na opção #\n");
            tocar_buzzer(freguencia, duracao);
            sleep_ms(100);
            break;
        case 'A':
            printf("Entrou na opção A\n");
            controlar_leds(operado);
            sleep_ms(100);
            break;
        case 'B':
            printf("Entrou na opção B\n");
            controlar_leds(operado);
            sleep_ms(100);
            break;
        case 'C':
            printf("Entrou na opção C\n");
            controlar_leds(operado);
            sleep_ms(100);
            break;
        case 'D':
            printf("Entrou na opção D\n");
            controlar_leds(operado);
            sleep_ms(100);
            break;
        default:
            sleep_ms(100);
            break;
        }
    }
    return 0;
}

// Função para verificar qual tecla foi pressionada
char verificar_tecla()
{
    for (int i = 0; i < linhas; i++)
    {
        gpio_put(linha_pins[i], 1);
        for (int j = 0; j < colunas; j++)
        {
            if (gpio_get(coluna_pins[j]))
            {
                gpio_put(linha_pins[i], 0);
                return mapa_tecla[i][j];
            }
        }
        gpio_put(linha_pins[i], 0);
    }
    return '\0'; // Retorna '\0' se nenhuma tecla for pressionada
}

// Função para inicializar os pinos
void inicializar_pinos()
{ // Inicializando as colunas do teclado matricial

    for (int i = 0; i < colunas; i++)
    {
        gpio_init(coluna_pins[i]);
        gpio_set_dir(coluna_pins[i], GPIO_IN);
        gpio_pull_down(coluna_pins[i]);
    }

    // Inicializando as linhas do teclado matricial
    for (int i = 0; i < linhas; i++)
    {
        gpio_init(linha_pins[i]);
        gpio_set_dir(linha_pins[i], GPIO_OUT);
        gpio_put(linha_pins[i], 0);
    }

    // Inicializando os leds green, blue e red
    for (int i = 0; i < leds; i++)
    {
        gpio_init(led_pin[i]);
        gpio_set_dir(led_pin[i], GPIO_OUT);
    }

    // Inicializando o pino do buzzer
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);
}

// Função para controlar os LEDs
void controlar_leds(char tecla)
{
    for (int i = 0; i < leds; i++)
    {
        gpio_put(led_pin[i], 0);
    }
    if (tecla == 'A')
    {
        gpio_put(led_pin[0], 1);
    }
    else if (tecla == 'B')
    {
        gpio_put(led_pin[1], 1);
    }
    else if (tecla == 'C')
    {
        gpio_put(led_pin[2], 1);
    }
    else if (tecla == 'D')
    { // Ligar todos os LEDs

        for (int i = 0; i < leds; i++)
        {
            gpio_put(led_pin[i], 1);
        }
    }
}

// Função para acionamento do buzzer
void tocar_buzzer(uint16_t FREGUENCIA, uint16_t DURACAO)
{
    uint32_t atraso = 1000000 / (2 * FREGUENCIA);
    uint32_t ciclos = (FREGUENCIA * DURACAO) / 1000;
    uint16_t i;

    for (i = 0; i < ciclos; i++)
    {
        gpio_put(buzzer_pin, 1);
        sleep_us(atraso);
        gpio_put(buzzer_pin, 0);
        sleep_us(atraso);
    }
}
