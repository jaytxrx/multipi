.globl _start
_start:
    mov sp,#0x8000 /*stack grows down*/
    bl main
loop: b loop
