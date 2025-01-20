# Controle de Pinos GPIO com Teclado Matricial

Projeto desenvolvido como parte da **Atividade 1** do programa **Embarcatech**, com o objetivo de controlar pinos GPIO utilizando um teclado matricial 4x4 no microcontrolador Raspberry Pi Pico W, simulando LEDs RGB e um buzzer.

## Descrição do Projeto

A atividade consiste em criar um programa em C utilizando o **Pico SDK**, simulando o seguinte hardware:

1. **Teclado matricial 4x4 (pinos 2, 3, 2 e 28 como saídas e pinos 5, 6, 7 e 8 como entradas)**
2. **03 LEDs RGB (pinos 11, 12 e 13)**
3. **Buzzer (pino 10)**
4. **Microcontrolador Raspberry Pi Pico W**

Com o auxílio do simulador de eletrônica **Wokwi**, o teclado 4x4 será utilizado para controlar o acionamento dos LEDs RGB e do sinal sonoro do buzzer. A estratégia de controle dos componentes fica a critério da equipe, promovendo liberdade criativa no desenvolvimento.

---



## Requisitos

- **Ambiente de desenvolvimento:** Visual Studio Code
- **Linguagem de programação:** C
- **SDK utilizado:** Pico SDK
- **Simulador:** Wokwi integrado ao VS Code

---



## Como Executar o Projeto

1. Clone este repositório:
   ```bash
   git clone https://github.com/Embarcatech-SubGrupo9/GPIO_Control_Teclado_4x4.git
   ```
2. Acesse o diretório do projeto:
   ```bash
   cd GPIO_Control_Teclado_4x4
   ```
3. Certifique-se de ter o Pico SDK configurado no ambiente de desenvolvimento.
4. Compile o programa:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
5. Execute a simulação no Wokwi.

---



## Estrutura do Repositório

- **GPIO_Control_Teclado_4x4.c:** Código principal do projeto.
- **README.md:** Documentação do projeto.
- **CMakeLists.txt:** Configurações do build.
- **Branches:** Cada membro da equipe possui um branch próprio para suas contribuições.
- **diagram.json** O diagrama do circuito com a placa raspberry pi pico w, teclado matricial, leds e buzzer.

---



## Resultados

### Funcionalidades:

* Leitura de todos os botões do teclado matricial e impressão no serial.
* Avionamento dos LEDs verde, azul e vermelho com os botões A, B e C. O botão D liga todos.
* Acionamento do buzzer com controle de intensidade através do PWM.

### Testes:

Os seguintes testes básicos foram implementados:

* Verificação do acionamento correto dos LEDs.
* Geração de sinal sonoro pelo buzzer.
* Leitura correta de todos os botões do teclado matricial.

### Link para o vídeo:

[Apresentação do Projeto]([https://link-do-video.com](https://www.dropbox.com/scl/fi/aczoznzc0ohi6fmcvengn/2025-01-19-22-44-23.mkv?rlkey=mr24ud3lnrdsvvnrouqywpqji&st=xqus8yuc&dl=0))

## 👥 Equipe de Desenvolvimento

- **Líder**: *Fernando Hali Santos Andrade*
- **Desenvolvedores**
- Leandro Alves dos Santos
- Heli Neres Silva
- Gabriel Adriano de Jesus Reis
- Luis Eduardo F. S. Pereira
