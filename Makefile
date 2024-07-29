COMMON_FLAGS = -mcpu=cortex-m4 -mthumb -O3 -Wall -Werror

SRC_FILES = stopwatch.c gpio.c
OBJ_FILES = $(SRC_FILES:.c=.o)

stopwatch.bin: stopwatch.elf
	arm-none-eabi-objcopy -O binary -S $< $@

stopwatch.elf: head.o $(OBJ_FILES)
	arm-none-eabi-gcc $^ -nostartfiles -Wl,-Ttext=0x8000000 -Wl,-Tbss=20000000 -o $@

$(OBJ_FILES): %.o: %.c
	arm-none-eabi-gcc $< $(COMMON_FLAGS) -c -o $@

head.o: head.S
	arm-none-eabi-gcc $< $(COMMON_FLAGS) -c -o $@

.PHONY: clean
clean:
	rm -f *.o *.elf *.bin

.PHONY: upload
upload: stopwatch.bin
	cp $< /media/$(USER)/NODE_L432KC

.PHONY: openocd
openocd:
	openocd -f ./nucleo-l4.cfg

.PHONY: gdb-multiarch
gdb-multiarch: stopwatch.elf
	gdb-multiarch --tui -ex="target remote localhost:3333" -ex="monitor reset init" -ex="b _start" $^