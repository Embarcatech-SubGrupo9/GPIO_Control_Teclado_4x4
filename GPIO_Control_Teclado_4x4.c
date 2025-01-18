#include "pico/stdlib.h"
#include "hardware/pwm.h"

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
    {'*', '0', '#', 'D'}
};

void iniciar_pinos(){
    //Inicialização dos pinos do buzzer
    gpio_init(buzzer_pin);
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM);
}

void tocar_buzzer(uint32_t faixa, uint32_t canal, uint32_t freguencia, uint32_t duracao);

int main()
{
    iniciar_pinos();
    uint32_t numero_faixa = pwm_gpio_to_slice_num(buzzer_pin);//Obtendo o número da faixa do PWM
    uint32_t canal = pwm_gpio_to_channel(buzzer_pin);//Obtendo o canal do PWM

    char operado = 'A';//Inicializando com A para acionamento da função
    while(1){
        switch (operado)
        {
        case 'A':
            tocar_buzzer(numero_faixa, canal, 1000, 500);
            tocar_buzzer(numero_faixa, canal, 600, 500);
            break;
        default:
            break;
        }
    }
}

//Função para acionamento do buzzer
void tocar_buzzer(uint32_t FAIXA, uint32_t CANAL, uint32_t freguencia, uint32_t duracao){
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