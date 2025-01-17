
```markdown
# Controle de Pinos GPIO com Teclado Matricial  
Projeto desenvolvido como parte da **Atividade 1** do programa **Embarcatech**, com o objetivo de controlar pinos GPIO utilizando um teclado matricial 4x4 no microcontrolador Raspberry Pi Pico W, simulando LEDs RGB e um buzzer.


## Descrição do Projeto  
A atividade consiste em criar um programa em C utilizando o **Pico SDK**, simulando o seguinte hardware:  
1. **Teclado matricial 4x4**  
2. **03 LEDs RGB**  
3. **Buzzer**  
4. **Microcontrolador Raspberry Pi Pico W**  

Com o auxílio do simulador de eletrônica **Wokwi**, o teclado 4x4 será utilizado para controlar o acionamento dos LEDs RGB e do sinal sonoro do buzzer. A estratégia de controle dos componentes fica a critério da equipe, promovendo liberdade criativa no desenvolvimento.  

## Requisitos  
- **Ambiente de desenvolvimento:** Visual Studio Code  
- **Linguagem de programação:** C  
- **SDK utilizado:** Pico SDK  
- **Simulador:** Wokwi integrado ao VS Code  

## Como Executar o Projeto  
1. Clone este repositório:  
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```  
2. Acesse o diretório do projeto:  
   ```bash
   cd seu-repositorio
   ```  
3. Certifique-se de ter o Pico SDK configurado no ambiente de desenvolvimento.  
4. Compile o programa:  
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```  
5. Execute a simulação no Wokwi.  

## Estrutura do Repositório  
- **GPIO_Control_Teclado_4x4.c:** Código principal do projeto.  
- **README.md:** Documentação do projeto.  
- **CMakeLists.txt:** Configurações do build.  
- **Branches:** Cada membro da equipe possui um branch próprio para suas contribuições. 
- **diagram.json** O diagrama da placa raspberry pi pico w e os outros componetes



## Resultados  
A solução e os resultados obtidos na simulação serão apresentados em um vídeo ensaio de até 3 minutos.  

### Link para o vídeo:  
[Apresentação do Projeto](https://link-do-video.com)  

## 👥 Equipe de Desenvolvimento

- **Líder**: *Fernando Hali Santos Andrade*  
- **Desenvolvedores**
- Angela Marim Bosetti  
- Leandro Alves dos Santos  
- Heli Neres Silva  
- Gabriel Adriano de Jesus Reis  
- Luis Eduardo F. S. Pereira  