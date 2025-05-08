#include<stdint.h>
#define KB 1024
#define RAM_SIZE (4 * KB)
#define START_RAM 0x20000000
#define END_RAM (START_RAM + RAM_SIZE - 4)
#define STACK_POINTER END_RAM

// void default_handler();
// void Reset_handler();
// //void Nmi_handler() __attribute__((weak,alias("default_handler")));
void main(void) __attribute__((weak,alias("default_handler")));
void __libc_init_array(void) __attribute__((weak,alias("default_handler")));
void initialise_monitor_handles();
// void Usart_handler(void) __attribute__((weak,alias("default_handler")));

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _ldata_;



void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak,alias("default_handler")));
void HardFault_Handler(void) __attribute__((weak,alias("default_handler")));
void UsageFault_Handler(void) __attribute__((weak,alias("default_handler")));
void Default_Handler(void) __attribute__((weak,alias("default_handler")));
void Svc_handler(void) __attribute__((weak,alias("default_handler")));

void WWDG_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void PVD_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void TAMPER_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void RTC_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void FLASH_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void RCC_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void EXTI0_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void EXTI1_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void EXTI2_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void EXTI3_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void EXTI4_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void DMA1_Channel5_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void DMA1_Channel6_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void DMA1_Channel7_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void ADC1_IRQHandler(void) __attribute__((weak,alias("default_handler")));

// 3 reserved slots (0x8C to 0x98)
void TIM1_BRK_TIM15_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void TIM1_UP_TIM16_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void TIM1_TRG_COM_TIM17_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void TIM2_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void TIM3_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void TIM4_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void USART1_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void USART2_IRQHandler(void) __attribute__((weak,alias("default_handler")));
void USART3_IRQHandler(void) __attribute__((weak,alias("default_handler")));


 uint32_t vector_table[] __attribute__((section(".isr_table"))) = {
    STACK_POINTER,                   // 0: Initial SP
    (uint32_t)Reset_Handler,              // 1: Reset
    (uint32_t)NMI_Handler,                // 2: NMI
    (uint32_t)HardFault_Handler,          // 3: Hard Fault
    (uint32_t)Default_Handler,            // 4: MemManage (unused)
    (uint32_t)Default_Handler,            // 5: BusFault (unused)
    (uint32_t)UsageFault_Handler,            // 6: UsageFault (unused)
    0, 0, 0, 0,                            // 7-10: Reserved
    (uint32_t)Svc_handler,            // 11: SVCall
    (uint32_t)Default_Handler,            // 12: Debug Monitor
    0,                                    // 13: Reserved
    (uint32_t)Default_Handler,            // 14: PendSV
    (uint32_t)Default_Handler,            // 15: SysTick

    // External Interrupts (IRQs)
    (uint32_t)WWDG_IRQHandler,            // 0
    (uint32_t)PVD_IRQHandler,             // 1
    (uint32_t)TAMPER_IRQHandler,          // 2
    (uint32_t)RTC_IRQHandler,             // 3
    (uint32_t)FLASH_IRQHandler,           // 4
    (uint32_t)RCC_IRQHandler,             // 5
    (uint32_t)EXTI0_IRQHandler,           // 6
    (uint32_t)EXTI1_IRQHandler,           // 7
    (uint32_t)EXTI2_IRQHandler,           // 8
    (uint32_t)EXTI3_IRQHandler,           // 9
    (uint32_t)EXTI4_IRQHandler,           // 10
    (uint32_t)DMA1_Channel1_IRQHandler,   // 11
    (uint32_t)DMA1_Channel2_IRQHandler,   // 12
    (uint32_t)DMA1_Channel3_IRQHandler,   // 13
    (uint32_t)DMA1_Channel4_IRQHandler,   // 14
    (uint32_t)DMA1_Channel5_IRQHandler,   // 15
    (uint32_t)DMA1_Channel6_IRQHandler,   // 16
    (uint32_t)DMA1_Channel7_IRQHandler,   // 17
    (uint32_t)ADC1_IRQHandler,            // 18
    0,                                    // 19: Reserved (0x8C)
    0,                                    // 20: Reserved (0x90)
    0,                                    // 21: Reserved (0x94)
    (uint32_t)TIM1_BRK_TIM15_IRQHandler,  // 22
    (uint32_t)TIM1_UP_TIM16_IRQHandler,   // 23
    (uint32_t)TIM1_TRG_COM_TIM17_IRQHandler, // 24
    (uint32_t)TIM1_CC_IRQHandler,         // 25
    (uint32_t)TIM2_IRQHandler,            // 26
    (uint32_t)TIM3_IRQHandler,            // 27
    (uint32_t)TIM4_IRQHandler,            // 28
    (uint32_t)I2C1_EV_IRQHandler,         // 29
    (uint32_t)I2C1_ER_IRQHandler,         // 30
    (uint32_t)I2C2_EV_IRQHandler,         // 31
    (uint32_t)I2C2_ER_IRQHandler,         // 32
    (uint32_t)USART1_IRQHandler,          // 33
    (uint32_t)USART2_IRQHandler,          // 34
    (uint32_t)USART3_IRQHandler,           // 35
    (uint32_t)USART3_IRQHandler,          // 36
    (uint32_t)USART1_IRQHandler,          // 37
    (uint32_t)USART2_IRQHandler           // 38
};



// uint32_t vector_table[73] __attribute__((section(".isr_table"))) = {
//     STACK_POINTER,
//     (uint32_t)Reset_handler
// //    (uint32_t)Nmi_handler
// };




void default_handler(){
    // default_handler
    asm volatile("mov r0, #5");
}

void Reset_Handler(){
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
   initialise_monitor_handles();
    
    //calling main
    main();
    //while(1);

}

int x = 10;
int y;
const int p = 100;