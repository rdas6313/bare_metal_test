/* Define memory regions */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 16K
    RAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 4K
}


SECTIONS
{
    
    .text :
    {
        *(.isr_table)
        *(.text)
        *(.init)
        *(.fini)
        . = ALIGN(4);
        *(.rodata)
        _etext = .;
    } > FLASH

    _ldata_ = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        __init_array_start = .;
        KEEP(*(.init_array))
        __init_array_end = .;
        . = ALIGN(4);
        __fini_array_start = .;
        KEEP(*(.fini_array))
        _fini_array_end = .;
        _edata = .;
    } > RAM AT > FLASH

    

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        __bss_start__ = _sbss;
        *(.bss)
        _ebss = .;
        __bss_end__ = _ebss;
        . = ALIGN(4);
        end = .;
    } > RAM

    _stack_top = ORIGIN(RAM) + LENGTH(RAM);

}