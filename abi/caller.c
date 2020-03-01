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
    int a = func_arg1(0x11111112);
    printf("func_arg1(0x11111112): %d\n", a);
}

void caller2(void) {
    int a = func_arg2(0x11111112, 0x22222223);
    printf("func_arg2(0x11111112, 0x22222223): %d\n", a);
}

void caller3(void) {
    int a = func_arg3(0x11111112, 0x22222223, 0x33333334);
    printf("func_arg3(0x11111112, 0x22222223, 0x33333334): %d\n", a);
}
