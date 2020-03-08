all: exe_O0 exe_O1 exe_O2 exe_O3 \
	exe_O0.txt exe_O1.txt exe_O2.txt exe_O3.txt \
	asm2_O0.S \

VPATH+=./bin ./objdump

CC=clang
CFLAGS=-I. -Wall -std=c11

# .S
asm2_O0.S: test_func2.c
	${CC} ${CFLAGS} -O0 -S -o $@ test_func2.c

# exe
exe_O0: asm.S test_func2.c main.c
	${CC} ${CFLAGS} -O0 -o bin/$@ asm.S test_func2.c main.c

exe_O1: asm.S test_func2.c main.c
	${CC} ${CFLAGS} -O1 -o bin/$@ asm.S test_func2.c main.c

exe_O2: asm.S test_func2.c main.c
	${CC} ${CFLAGS} -O2 -o bin/$@ asm.S test_func2.c main.c

exe_O3: asm.S test_func2.c main.c
	${CC} ${CFLAGS} -O3 -o bin/$@ asm.S test_func2.c main.c

# objdump
exe_O0.txt: exe_O0
	objdump -d -C bin/exe_O0 > objdump/$@

exe_O1.txt: exe_O1
	objdump -d -C bin/exe_O1 > objdump/$@

exe_O2.txt: exe_O2
	objdump -d -C bin/exe_O2 > objdump/$@

exe_O3.txt: exe_O3
	objdump -d -C bin/exe_O3 > objdump/$@

clean:
	rm -f asm2_O0.S bin/exe_*
