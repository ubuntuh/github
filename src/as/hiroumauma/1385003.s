    .globl main
main:
    # write(1, msg, 13)
    movl $4, %eax
    movl $1, %ebx
    movl $msg, %ecx
    movl $13, %edx
    int $0x80

    # exit(0)
    movl $1, %eax
    movl $0, %ebx
    int $0x80

    .data
msg:
    .asciz "hello, world\n"
