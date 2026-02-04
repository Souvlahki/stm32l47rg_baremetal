#include <stdint.h>
#include <stdbool.h>
#include "stm32l476xx.h"

#include "gpio.h"
#include "uart.h"

#define LED_PIN                 (5)
#define BUTTON_PIN              (13)

#define BAUDRATE                (9600)

int main() {
    usart2_init(BAUDRATE);
    gpio_set_pin_mode(GPIOA, LED_PIN, GPIO_MODE_OUTPUT);
    char k;
    
    while(1) {
        k = usart2_read();  

        if(k == '1') {
            gpio_write_pin(GPIOA, LED_PIN, GPIO_HIGH);
        } else {
            gpio_write_pin(GPIOA, LED_PIN, GPIO_LOW);
        }
         
    }
}