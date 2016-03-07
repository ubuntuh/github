    .globl main
main:
    movb $0x7f, %al # 0x7f = 127 -> next -128
    inc %al # OF (overflow flag) = 1
    jo overflow # jump if overflow
end:
    # exit(0)
    movl $1, %eax
    movl $0, %ebx
    int $0x80
overflow:
    # write(1, msg, len)
    movl $4, %eax
    movl $1, %ebx
    movl $msg, %ecx
    movl $len, %edx
    int $0x80

    jmp end

    .data
msg:
    .asciz "OVERFLOW\n"
msgend:
    .equ len, msgend - msg
