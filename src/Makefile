# -I/usr/lib/gcc/arm-none-eabi/10.3.1/include -I/usr/lib/gcc/arm-none-eabi/10.3.1/include-fixed
CC = arm-none-eabi-gcc
CPU = cortex-m3
CFLAGS = -c -O0 -mcpu=$(CPU) -mthumb -g -std=gnu11 -mfloat-abi=soft 
LFLAGS = -Wl,-Map=final.map -Wall -g --specs=nano.specs -mcpu=$(CPU) -mthumb -mfloat-abi=soft
LFLAGS_SH = -Wl,-Map=final.map -Wall -g --specs=rdimon.specs -mcpu=$(CPU) -mthumb -mfloat-abi=soft -u _printf_int -u _printf_float -lc -lrdimon

.PHONY: clear run run_sh semihost

firmware.elf: startup.o main.o syscalls.o
	$(CC) $(LFLAGS) -T linker.ld $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

semihost: firmware_sh.elf

firmware_sh.elf: startup.o main.o
	$(CC) $(LFLAGS_SH) -T linker.ld $^ -o $@

run:
	qemu-system-arm -M stm32vldiscovery -cpu cortex-m3 -kernel firmware.elf  -serial mon:stdio -nographic -S -s

run_sh:
	qemu-system-arm -M stm32vldiscovery -cpu cortex-m3 -semihosting-config enable=on,target=native -kernel firmware_sh.elf -nographic -S -s
clear:
	rm -rf *.o *.elf *.map .gdb_history