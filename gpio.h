#ifndef GPIO_H_
#define GPIO_H_

#include "registers.h"

typedef struct gpio_port {
    uint32_t mode;
    uint32_t RESERVED1;
    uint32_t RESERVED2;
    uint32_t RESERVED3;
    uint16_t input;
    uint16_t RESERVED4;
    uint16_t output;
    uint16_t RESERVED5;
    uint32_t RESERVED6;
    uint32_t RESERVED7;
    uint64_t function;
    uint32_t RESERVED8;
} gpio_port;

typedef enum gpio_pin {
    PIN0 = 0,
    PIN1 = 1,
    PIN2 = 2,
    PIN3 = 3,
    PIN4 = 4,
    PIN5 = 5,
    PIN6 = 6,
    PIN7 = 7,
    PIN8 = 8,
    PIN9 = 9,
    PIN10 = 10,
    PIN11 = 11,
    PIN12 = 12,
    PIN13 = 13,
    PIN14 = 14,
    PIN15 = 15
} gpio_pin;

typedef enum gpio_mode {
    INPUT = 0,
    OUTPUT = 1,
    ALTERNATE = 2,
    ANALOG = 3
} gpio_mode;

typedef enum gpio_state {
    LOW = 0,
    HIGH = 1
} gpio_state;

typedef enum gpio_function {
    AF0 = 0,
    AF1 = 1,
    AF2 = 2,
    AF3 = 3,
    AF4 = 4,
    AF5 = 5,
    AF6 = 6,
    AF7 = 7,
    AF8 = 8,
    AF9 = 9,
    AF10 = 10,
    AF11 = 11,
    AF12 = 12,
    AF13 = 13,
    AF14 = 14,
    AF15 = 15
} gpio_function;

void gpio_set_mode(volatile gpio_port* port, gpio_pin pin, gpio_mode mode);
gpio_state gpio_read_pin(volatile gpio_port* port, gpio_pin pin);
void gpio_write_pin(volatile gpio_port* port, gpio_pin pin, gpio_state state);
void gpio_toggle_pin(volatile gpio_port* port, gpio_pin pin);
void gpio_set_function(volatile gpio_port* port, gpio_pin pin, gpio_function function);

static volatile gpio_port *const GPIOA = (gpio_port*)(GPIOA_BASE);
static volatile gpio_port *const GPIOB = (gpio_port*)(GPIOB_BASE);

#endif