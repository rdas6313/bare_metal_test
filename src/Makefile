# -I/usr/lib/gcc/arm-none-eabi/10.3.1/include -I/usr/lib/gcc/arm-none-eabi/10.3.1/include-fixed
CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m3 -mthumb -g -std=gnu11
LFLAGS = -Wl,-Map=final.map -Wall -g --specs=nano.specs

.PHONY: clear


firmware.elf: startup.o main.o syscalls.o
	$(CC) $(LFLAGS) -T linker.ld $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

run:
	qemu-system-arm -M stm32vldiscovery -cpu cortex-m3 -kernel firmware.elf -nographic -S -s

clear:
	rm -rf *.o *.elf *.map .gdb_history