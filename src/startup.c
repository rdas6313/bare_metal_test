#include<stdint.h>
#define KB 1024
#define RAM_SIZE (4 * KB)
#define START_RAM 0x20000000
#define END_RAM (START_RAM + RAM_SIZE)
#define STACK_POINTER END_RAM

void default_handler();
void Reset_handler();
void Nmi_handler() __attribute__((weak,alias("default_handler")));

uint32_t vector_table[73] __attribute__((section(".isr_table"))) = {
    STACK_POINTER,
    (uint32_t)Reset_handler,
    (uint32_t)Nmi_handler
};

void default_handler(){
    // default_handler
}

void Reset_handler(){
    //reset_handler
}

int x = 10;
int y;
const int p = 100;