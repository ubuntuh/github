    .global main

    .text
main:
    mov     $1, %rax
    mov     $1, %rdi
    mov     $message, %rsi
    mov     $13, %rdx
    syscall

    mov     $60, %rax
    xor     %rdi, %rdi
    syscall
message:
    .ascii  "hello, world\n"
