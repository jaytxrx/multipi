
/*RAM begins at address 0x8000. Assuming 20Kb of RAM */

MEMORY
{
    ram : ORIGIN = 0x8000, LENGTH = 20K
}

SECTIONS
{
    .text : { *(.text*) } > ram
    .bss : { *(.bss*) } > ram
}