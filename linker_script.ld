ENTRY(reset_handler)

MEMORY
{
	FLASH (rx): ORIGIN = 0x08000000,LENGTH = 256K
	SRAM (rwx): ORIGIN = 0x20000000,LENGTH = 64K
}

SECTIONS
{
	.isr_vector :
	{
	  . = ORIGIN(FLASH); 
	  KEEP(*(.isr_vector))
	  . = ALIGN(4);      
	}>FLASH
	
	.text :
	{
		. = ALIGN(4);

		*(.text)
		*(.rodata)

		. = ALIGN(4);

		_etext = .;

	}>FLASH
     
	.data :
	{
		. = ALIGN(4);

		_sdata = .;

		*(.data)

		. = ALIGN(4);

		_edata = .;
	}>SRAM AT >FLASH

	.bss :
	{
		. = ALIGN(4);
		_sbss = .;

		*(.bss)

		. = ALIGN(4);

		_ebss = .;
	}>SRAM

	    /* Define the end of stack (top address of SRAM) */
    .stack_top (NOLOAD): /* NOLOAD means it won't take space in the output binary */
    {
        . = ALIGN(8); 
        _estack = ORIGIN(SRAM) + LENGTH(SRAM); 
    } >SRAM

}