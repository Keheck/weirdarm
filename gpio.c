#include <stdint.h>
#include "gpio.h"

void gpio_set_mode(volatile gpio_port* port, gpio_pin pin, gpio_mode mode) {
    port->mode = (port->mode & ~(0b11 << pin*2)) | (mode << pin*2);
}

gpio_state gpio_read_pin(volatile gpio_port* port, gpio_pin pin) {
    return (port->input & (1 << pin)) != 0 ? HIGH : LOW;
}

void gpio_write_pin(volatile gpio_port* port, gpio_pin pin, gpio_state state) {
    if(state == HIGH)
        port->output |= 1 << pin;
    else
        port->output &= ~(1 << pin);
}

void gpio_toggle_pin(volatile gpio_port* port, gpio_pin pin) {
    port->output ^= 1 << pin;
}

void gpio_set_function(volatile gpio_port* port, gpio_pin pin, gpio_function function) {
    port->function = (port->function & ~(0b1111 << pin*4)) | ((function << pin*4));
}
