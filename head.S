.global _start
.global systick
.global timer_toggle
.equ STACK_HIGH, 0x20010000

Vectors:
    .word STACK_HIGH
    .word _start+1
.org 0x3C
    .word systick
.org 0x58
    .word timer_toggle
