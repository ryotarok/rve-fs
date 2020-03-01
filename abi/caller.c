#include <stdio.h>

extern int func_arg0(void);
extern int func_arg1(int a0);
extern int func_arg2(int a0, int a1);
extern int func_arg3(int a0, int a1, int a2);

void caller0(void) {
    int a = func_arg0();
    printf("func_arg0(): %d\n", a);
}

void caller1(void) {
    int a = func_arg1(16);
    printf("func_arg1(16): %d\n", a);
}

void caller2(void) {
    int a = func_arg2(32, 64);
    printf("func_arg2(32, 64): %d\n", a);
}

void caller3(void) {
    int a = func_arg3(128, 256, 512);
    printf("func_arg3(128, 256, 512): %d\n", a);
}
