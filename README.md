# 🚀 Projeto: Controle de LEDs e Display com RP2040

## 📌 Descrição
Este projeto utiliza a placa de desenvolvimento **BitDogLab** com o microcontrolador **RP2040** para controlar **LEDs RGB**, uma matriz de LEDs **WS2812** e um display OLED **SSD1306**. Além disso, implementa comunicação **UART** para entrada de caracteres e utiliza interrupções para interação com botões.

## 🛠️ Componentes Utilizados
- 🔌 **Placa de desenvolvimento**: BitDogLab (RP2040)
- 🔴🟢🔵 **LED RGB** (GPIOs 11, 12 e 13)
- 🎛️ **Matriz 5x5 de LEDs WS2812** (GPIO 7)
- 🔘 **Botão A** (GPIO 5)
- 🔘 **Botão B** (GPIO 6)
- 📟 **Display OLED SSD1306** via I2C (GPIO 14 e GPIO 15)
- 🔄 **Comunicação UART** (TX: GPIO 0, RX: GPIO 1)

## 🎯 Funcionalidades
- **💡 Controle de LEDs**: Alternância de estados dos LEDs RGB via botões.
- **🎛️ Interação com botões**:
  - 🟢 **Botão A**: Liga/desliga o LED Verde e exibe mensagens no display e Serial Monitor.
  - 🔵 **Botão B**: Liga/desliga o LED Azul e exibe mensagens no display e Serial Monitor.
- **🔢 Matriz WS2812**:
  - Exibe um símbolo correspondente ao número digitado via UART.
- **💬 Comunicação UART**:
  - Entrada de caracteres via Serial Monitor.
  - Exibição de caracteres no display OLED.
  
## ⚙️ Instalação e Configuração
1. 🔧 Instale o **SDK do Raspberry Pi Pico**.
2. 🖥️ Configure o ambiente de desenvolvimento com **VS Code** e **CMake**.
3. 🔌 Conecte a **placa BitDogLab** ao computador via USB.
4. 📥 Compile e carregue o código na placa RP2040.

## 🎮 Como Usar
1. 🔘 **Pressione o Botão A** para ligar/desligar o LED Verde.
2. 🔘 **Pressione o Botão B** para ligar/desligar o LED Azul.
3. ⌨️ **Digite caracteres** no **Serial Monitor** do VS Code para vê-los no display.
4. 🔢 **Digite números (0-9)** para exibir um símbolo correspondente na matriz WS2812.

## 📂 Estrutura do Código
```
├── src/
│   ├── main.c  # Código principal
│   ├── ssd1306.c  # Biblioteca do display OLED
│   ├── ws2812.c  # Biblioteca dos LEDs WS2812
├── include/
│   ├── ssd1306.h  
│   ├── ws2812.h
├── CMakeLists.txt
└── README.md
```

## 📦 Entrega
- 📜 **Código-fonte**: Disponível no repositório Git.
## ✨ Autor
Brunna Barreto da Silva
20241bsifsa0027@ifba.edu.br

