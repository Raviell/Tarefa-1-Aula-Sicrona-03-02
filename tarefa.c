#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "hardware/i2c.h"
#include "ws2812.pio.h"
#include "ssd1306.h"

// Definições de pinos
#define LED_R 11
#define LED_G 12
#define LED_B 13
#define BTN_A 5
#define BTN_B 6
#define WS2812_PIN 7
#define I2C_SDA 14
#define I2C_SCL 15
#define UART_TX 0
#define UART_RX 1

// Variáveis globais
bool led_g_state = false;
bool led_b_state = false;

void debounce()
{
    sleep_ms(50); // Delay simples para debounce
}

// Função para exibir número na matriz WS2812
void display_number_ws2812(int num)
{
    uint32_t colors[25] = {0}; // Matriz 5x5
    for (int i = 0; i < num; i++)
    {
        colors[i] = 0x00FF00; // Verde para representar o número
    }
    ws2812_put_pixel(colors, 25);
}

// Interrupção do Botão A
void btn_a_irq_handler(uint gpio, uint32_t events)
{
    debounce();
    led_g_state = !led_g_state;
    gpio_put(LED_G, led_g_state);
    printf("Botão A pressionado. LED Verde: %s\n", led_g_state ? "Ligado" : "Desligado");
    ssd1306_clear();
    ssd1306_write_string(led_g_state ? "LED Verde ON" : "LED Verde OFF");
}

// Interrupção do Botão B
void btn_b_irq_handler(uint gpio, uint32_t events)
{
    debounce();
    led_b_state = !led_b_state;
    gpio_put(LED_B, led_b_state);
    printf("Botão B pressionado. LED Azul: %s\n", led_b_state ? "Ligado" : "Desligado");
    ssd1306_clear();
    ssd1306_write_string(led_b_state ? "LED Azul ON" : "LED Azul OFF");
}

int main()
{
    stdio_init_all();

    // Configuração de GPIOs
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &btn_a_irq_handler);

    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, &btn_b_irq_handler);

    // Configuração do display SSD1306
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init();

    // Configuração WS2812
    ws2812_init(WS2812_PIN);

    // Loop principal
    while (1)
    {
        int c = getchar_timeout_us(100000);
        if (c != PICO_ERROR_TIMEOUT)
        {
            char msg[2] = {(char)c, '\0'};
            printf("Recebido: %c\n", c);
            ssd1306_clear();
            ssd1306_write_string(msg);
            
            if (c >= '0' && c <= '9')
            {
                int num = c - '0';
                display_number_ws2812(num);
                printf("Número %d exibido na matriz WS2812\n", num);
                ssd1306_clear();
                ssd1306_write_string("Exibindo número");
            }
        }
    }
}