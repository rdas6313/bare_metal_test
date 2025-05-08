#include <stdio.h>
#include<stdint.h>

__attribute__((optimize("O0")))
void test(){
    int y = 10;
    printf("Hello from Linux\n");
}

void USART1_IRQHandler(void){
    //printf("Usart!");
    uint32_t* ISPR = (uint32_t*)(0XE000E200);
    *ISPR |= (1<<0);
    asm volatile("mov r0,#1");
    asm volatile("mov r1,#2");
}

void USART2_IRQHandler(void){
    //printf("Usart!");
    asm volatile("mov r0,#2");
}
void USART3_IRQHandler(void){
    //printf("Usart!");
    asm volatile("mov r0,#3");
}

void WWDG_IRQHandler(void){
    asm volatile("mov r0,#4");
}

int add(int a,int b){
    return a+b;
}

void setpriority(uint8_t irq_no,uint32_t priority){
    uint32_t *IPR_BASE = (uint32_t*)0xE000E400;
    uint8_t register_no = irq_no / 4;
    uint8_t index = irq_no % 4;
    uint8_t shift_value = index * 8;
    uint32_t* final = (IPR_BASE + register_no);
    *final |= (priority << shift_value);
    
}

void HardFault_Handler(void){
    while(1);
}

__attribute__((naked))
void UsageFault_Handler(void){
    asm volatile("MRS r0,MSP");
    asm volatile("b UsageFault_Handler_C");
}

void UsageFault_Handler_C(uint32_t* stack){
    
    while(1);
}

__attribute__((naked))
void Svc_handler(void){
    asm volatile("MRS r0,MSP");
    asm volatile("b Svc_handler_c");
}

void Svc_handler_c(uint32_t* stack_ptr){
    uint8_t* pc = (uint8_t*)stack_ptr[6];
    pc -= 2;
    uint8_t irq = *pc;
    uint8_t a,b;
    switch(irq){
        case 5:
            a = stack_ptr[0];
            b = stack_ptr[1];
            stack_ptr[0] = a + b;
            break;
        default:
            stack_ptr[0] = 0;
    }

}

void main()
{

    
    // int x = 2;
    // x = x + 1;
    // printf("X= %d  \n", x);
    // my_label:
    // printf("You are at my_label\n");

    // void *addr = (void*)0x000002d9;

    // asm volatile("mov r0,%0" ::"r"(addr));
    // goto *addr;

    
    // void (*p)(void) = (void *)(0x000002a5);
    // p();
    // x = 10;
    // uint8_t x = 0xff;
    // uint8_t *q = &x;

    // uint8_t *p = (uint8_t *)((uint32_t)0x22000000 + (32 * ((uint32_t)&x - (uint32_t)0x20000000)) + (7 * 4));

    // *p = 0;

    // asm volatile("MRS r1, PRIMASK");
    // asm volatile("MRS r2, FAULTMASK");

    // int data[] = {2,3};
    // int c = add(data[0],data[1]);

    
    
    // setpriority(0,0x00);
    // setpriority(37,0x00);

    // uint32_t* ISER = (uint32_t*)(0xE000E104);
    // *ISER |= (1<<5);

    // uint32_t* ISER0 = (uint32_t*)(0xE000E100);
    // *ISER0 |= (1<<0);

    // uint32_t* ISPR = (uint32_t*)(0XE000E204);
    // *ISPR |= (1<<5);
    
    // uint32_t* config_register = (uint32_t*)0xE000ED14;
    // *config_register |= (1<<4);
    // uint32_t* SHCR = (uint32_t*)0xE000ED24;
    // *SHCR |= (1<<18);
    // int a = 5;
    // int b = 0;
    // int x = a/b;
    if (1)
    printf("%d\n", 123);
    int result;
    asm volatile("mov r0, #10");
    asm volatile("mov r1, #5");
    asm volatile("SVC #0x5");
    asm volatile("str r0, %0":"=m"(result));
   
    printf("Semihost activated\n");
    
    printf("Result %d\n",result);
    // fflush(stdout);
    // printf("Hello\n");
    // fflush(stdout);
    char buffer[100];
    sprintf(buffer, "Result = %d\n", result);
    puts(buffer);


}