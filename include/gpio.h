#ifndef GPIO_H_
#define GPIO_H_

#include "stm32l476xx.h"

typedef enum {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG,
} gpio_mode_t;


typedef enum {
    GPIO_LOW,
    GPIO_HIGH,
} gpio_state_t;



void gpio_set_pin_mode(GPIO_TypeDef *port, uint16_t pin, gpio_mode_t mode);
void gpio_write_pin(GPIO_TypeDef *port, uint16_t pin, gpio_state_t state);
void gpio_toggle_pin(GPIO_TypeDef *port, uint16_t pin);
gpio_state_t gpio_read_pin(GPIO_TypeDef *port, uint16_t pin);


#endif