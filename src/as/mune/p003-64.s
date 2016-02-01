    .text
    .globl main
main:
    mov $7, %rax
    mov %rax, %rbx
    mul %rax
    add %rbx, %rax
    sar %rax

    mov $MES, %rdi
    mov %rax, %rsi
    xor %rax, %rax
    call printf
    ret
    
    .data
MES:
    .string "%d\n"
