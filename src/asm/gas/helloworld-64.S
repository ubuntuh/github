// gcc -nostdlib helloworld-64.S
    #include <syscall.h>
    #define STDOUT 1

    .data
message:
    .ascii  "hello, world\n"
    length  = . - message

    .text
    .global _start
_start:
    movq    $SYS_write, %rax
    movq    $STDOUT, %rdi
    movq    $message, %rsi
    movq    $length, %rdx
    syscall

    movq    $SYS_exit, %rax
    xorq    %rdi, %rdi
    syscall

    ret
