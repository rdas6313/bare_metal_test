CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m3 -mthumb
LFLAGS = -Wl,-Map=final.map -nostdlib -Wall

.PHONY: clean


firmware.elf: startup.o
	$(CC) $(LFLAGS) -T linker.ld $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf *.o *.elf *.map