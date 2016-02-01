// gcc helloworld_printf.s
    .data
message:
    .string  "hello, world %d\n"

    .text
    .global main
main:
    movq    $message, %rdi
    movq    $100, %rsi
    xorq    %rax, %rax
    call printf

    xorq    %rdi, %rdi
    call exit
    
    ret
