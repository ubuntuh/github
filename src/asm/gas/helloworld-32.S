// gcc -m32 -nostdlib helloworld-32.S
    #include <syscall.h>
    #define STDOUT 1

    .data
message:
    .ascii  "hello, world\n"
    length  = . - message

    .text
    .global _start
_start:
    movl    $SYS_write, %eax
    movl    $STDOUT, %ebx
    movl    $message, %ecx
    movl    $length, %edx
    int     $0x80

    movl    $SYS_exit, %eax
    xorl    %ebx, %ebx
    int     $0x80

    ret
