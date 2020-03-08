#include <stdio.h>

void test_func2(void) {
    printf("a = %llx, b = %llx\n", 0x12ffffffffffff34, 0x56ffffffffffff78);
}

typedef void (pf)(void);

void test_func3(void) {
    pf *p = test_func2;
    (*p)();
}
