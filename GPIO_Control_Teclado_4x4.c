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
void tocar_buzzer(uint32_t faixa, uint32_t canal, uint32_t freguencia, uint32_t duracao);

int main()
{
    uint8_t i = 0;
    uint16_t freguencia, duracao;
    inicializar_pinos();
    uint32_t numero_faixa = pwm_gpio_to_slice_num(buzzer_pin); // Obtendo o número da faixa do PWM
    uint32_t canal = pwm_gpio_to_channel(buzzer_pin);          // O
    stdio_init_all();

    while (true)
    {
        char operado = verificar_tecla();
        switch (operado)
        {
        case '#':
            printf("Entrou na opção #\n");
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
        }
        >>>>>>>
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
    // Iniciando o pino para acionamento do buzzer
    gpio_init(buzzer_pin);
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM);
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
void tocar_buzzer(uint32_t FAIXA, uint32_t CANAL, uint32_t freguencia, uint32_t duracao)
{
    uint32_t Freq_clock = 125000000;
    uint32_t divisor_clock = Freq_clock / (freguencia * 4096);
    pwm_set_clkdiv(FAIXA, divisor_clock);

    uint16_t level = 2048;
    pwm_set_gpio_level(buzzer_pin, level);
    pwm_set_wrap(FAIXA, 4095);
    pwm_set_chan_level(FAIXA, CANAL, level);
    pwm_set_enabled(FAIXA, true);

    sleep_ms(duracao);

    pwm_set_enabled(FAIXA, 0);
}