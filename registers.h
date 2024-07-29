#ifndef REGISTERS_H_
#define REGISTERS_H_

#include <stdint.h>

#define GPIOA_BASE 0x48000000
#define GPIOB_BASE 0x48000400
#define RCC_BASE   0x40021000
#define EXTI_BASE  0x40010400
#define STK_BASE   0xE000E010
#define NVIC_BASE  0xE000E000

static volatile uint32_t *const RCCAHB2_ENABLE = (uint32_t*)(RCC_BASE+0x4C);

static volatile uint32_t *const STK_CTL        = (uint32_t*)(STK_BASE+0x00);
static volatile uint32_t *const STK_LOAD       = (uint32_t*)(STK_BASE+0x04);
static volatile uint32_t *const STK_VAL        = (uint32_t*)(STK_BASE+0x08);

static volatile uint32_t *const EXTI_IMR1      = (uint32_t*)(EXTI_BASE+0x00);
static volatile uint32_t *const EXTI_RTS1      = (uint32_t*)(EXTI_BASE+0x08);
static volatile uint32_t *const EXTI_PR1       = (uint32_t*)(EXTI_BASE+0x14);

static volatile uint32_t *const NVIC_ISER0     = (uint32_t*)(NVIC_BASE+0x100);

#endif