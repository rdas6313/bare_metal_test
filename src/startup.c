#include<stdint.h>
#define KB 1024
#define RAM_SIZE (4 * KB)
#define START_RAM 0x20000000
#define END_RAM (START_RAM + RAM_SIZE)
#define STACK_POINTER END_RAM

void default_handler();
void Reset_handler();
//void Nmi_handler() __attribute__((weak,alias("default_handler")));
void main(void);
void __libc_init_array(void);

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _ldata_;

uint32_t vector_table[73] __attribute__((section(".isr_table"))) = {
    STACK_POINTER,
    (uint32_t)Reset_handler
//    (uint32_t)Nmi_handler
};

// void default_handler(){
//     // default_handler
// }

void Reset_handler(){
    //reset_handler
    /*Copying data section from flash to SRAM */
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t *ptr_ram = (uint8_t *)&_sdata;
    uint8_t *ptr_flash = (uint8_t *)&_ldata_;
    for(uint32_t i = 0; i < size; i++)
        *ptr_ram++ = *ptr_flash++;

    /*Initializing bss section to zero */
    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    ptr_ram = (uint8_t *)&_sbss;
    for(uint32_t i = 0; i < size; i++)
        *ptr_ram++ = 0;
    
    //initializing Newlib c library
    __libc_init_array();
    //calling main
    main();

}

int x = 10;
int y;
const int p = 100;