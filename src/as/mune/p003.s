/* gcc -m32 p003.s */
    .text
    .globl main
main:
    mov $7,%eax
    mov %eax,%ebx
    mul %eax
    add %ebx,%eax
    sar %eax

    # Error: operand type mismatch for push
    push %eax 
    push $MES
    call printf
    add $8,%esp
    xor %eax,%eax
    ret
    
    .data
MES:
    .string "%d\n"
