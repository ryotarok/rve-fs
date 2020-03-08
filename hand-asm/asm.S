    .global _test_func
    .p2align	4, 0x90
_test_func:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    movabs $format, %rdi
    movabs $0x12FFFFFFFFFFFFBB, %rsi
    movabs $0x34FFFFFFFFFFFFCC, %rdx
    movb $0, %al
    callq _printf
    movl %eax, -4(%rbp)
    addq $16, %rsp
    popq %rbp
    retq

format:
    .asciz "a = %016lx, b = %016lx\n"
