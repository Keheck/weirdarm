#include <stdint.h>
#include "gpio.h"
#include "registers.h"

void systick() {
    gpio_toggle_pin(GPIOB, PIN3);
}

void timer_toggle() {
    //__asm__("push {lr}");

    *STK_CTL ^= 1;
    // Required to enable the interrupt again
    *EXTI_PR1 = 1 << 0;
    
    //__asm__("pop {pc}");
}

int _start() {
    // Enable the clock for GPIO A and GPIO B
    *RCCAHB2_ENABLE |= 0b11;
    // Configure built-in LED (LD3) as output (used in the systick ISR for blinking)
    gpio_set_mode(GPIOB, PIN3, OUTPUT);

    // Configure pin PA0 as input (button that triggers the timer_toggle ISR)
    gpio_set_mode(GPIOA, PIN0, INPUT);
    // Configure pin PA3 as output (hook up the external LED here, used for debugging)
    gpio_set_mode(GPIOA, PIN3, OUTPUT);

    // In the default configuration, 2,000,000 is equivalent to 500ms on the L432KC
    *STK_LOAD = 2000000;
    *STK_VAL = 0;
    // Enable the interrupt, the counter and use the processor clock
    *STK_CTL = 0b111;

    // Enable the EXTI line 0, hooked up to PA0
    *EXTI_IMR1 |= 0b1;
    // Trigger EXTI0 on rising edge (button depressed)
    *EXTI_RTS1 |= 0b1;

    // Enable EXTI0 as an interrupt in the NVIC
    *NVIC_ISER0 |= 0b1 << 6;

    // Loop infinitely....
    while(1);
}
