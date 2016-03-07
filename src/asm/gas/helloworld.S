// gcc helloworld.S
    #include <syscall.h>
    #define STDOUT 1

    .data
message:
    .ascii  "hello, world\n"
messageend: 

    .text
    .global main
main:
    movq    $SYS_write, %rax
    movq    $STDOUT, %rdi
    movq    $message, %rsi
    movq    $messageend - message, %rdx
    syscall

    movq    $SYS_exit, %rax
    xorq    %rdi, %rdi
    syscall

    ret
