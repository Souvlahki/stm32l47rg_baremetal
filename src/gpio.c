#include "gpio.h"


void gpio_set_pin_mode(GPIO_TypeDef *port, uint16_t pin, gpio_mode_t mode) {
    port -> MODER &=~ (3U << (pin * 2)); // resets the pin mode
    
    port -> MODER |= mode << (pin * 2); 
}

void gpio_write_pin(GPIO_TypeDef *port, uint16_t pin, gpio_state_t state) {
    if(state == GPIO_HIGH) {
        port -> BSRR = 1U << pin;
        return;
    }

    port -> BSRR = 1U << (pin + 16);
}

void gpio_toggle_pin(GPIO_TypeDef *port, uint16_t pin) {
    port -> ODR ^= 1U << pin;
}

gpio_state_t gpio_read_pin(GPIO_TypeDef *port, uint16_t pin) {
    return (port->IDR & (1U << pin)) ? GPIO_HIGH : GPIO_LOW;
}