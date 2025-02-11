# Controle de Servomotor e LED com PWM na Raspberry Pi Pico W

Este projeto implementa o controle de um servomotor padrão e o ajuste do brilho de um LED RGB utilizando o módulo PWM do microcontrolador RP2040 (Raspberry Pi Pico W). A solução atende aos requisitos da atividade proposta, que envolve:

- Configuração do PWM para 50 Hz (período de 20 ms);
- Definição de ciclos ativos específicos para posicionar o servo em 0°, 90° e 180°;
- Movimentação suave do servomotor entre os ângulos de 0° e 180°;
- Ajuste do brilho do LED (GPIO 12) de forma proporcional à posição do servomotor.

## Descrição do Projeto

Este projeto foi desenvolvido para a atividade **"Controle de servomotor por PWM"** e utiliza o Pico SDK com a linguagem C para controlar tanto um servomotor (através do PWM no GPIO 22) quanto um LED RGB (através do PWM no GPIO 12). A simulação pode ser realizada utilizando o simulador de eletrônica online [Wokwi](https://wokwi.com/).

## Funcionalidades

- **Configuração do PWM:**  
  - Frequência definida para 50 Hz (período de 20 ms) utilizando um divisor de clock que gera 1 µs por tick.
  - Wrap configurado para 19.999, totalizando 20.000 ticks (20 ms).

- **Controle do Servomotor:**  
  - **180°:** Ciclo ativo de 2400 µs – aguarda 5 segundos.
  - **90°:** Ciclo ativo de 1470 µs – aguarda 5 segundos.
  - **0°:** Ciclo ativo de 500 µs – aguarda 5 segundos.
  - **Movimentação suave:** Incremento de 5 µs a cada 10 ms para transição suave entre 0° e 180°.

- **Controle do LED RGB:**  
  - O brilho do LED (GPIO 12) é ajustado proporcionalmente à posição do servomotor, demonstrando o uso do PWM para controle de intensidade luminosa.

## Ferramentas e Tecnologias

- **Linguagem:** C
- **Plataforma:** Raspberry Pi Pico W com microcontrolador RP2040
- **Ambiente de Desenvolvimento:** Visual Studio Code
- **SDK:** Pico SDK
- **Simulação:** Wokwi
- **Ferramenta Experimental:** BitDogLab (para experimentos com o LED RGB)

## Estrutura do Projeto

```plaintext

├── CMakeLists.txt # Configuração para compilação com Pico SDK 
├── main.c # Código fonte principal do projeto 
└── README.md # Este arquivo de documentação

```

## Instruções de Uso

### Pré-requisitos

- **Hardware:** Raspberry Pi Pico W (ou uso do simulador Wokwi para teste).
- **Software:**  
  - Visual Studio Code configurado para desenvolvimento em C.
  - Pico SDK instalado e configurado conforme a [documentação oficial](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
  - Git (para clonagem do repositório).


## Link do Video

-https://www.youtube.com/watch?v=FZf1PEL8d0k

## Autor

-Deividson Ribeiro Silva
