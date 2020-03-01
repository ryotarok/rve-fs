all: \
	callee_O0.S callee_O1.S callee_O2.S callee_O3.S \
	caller_O0.S caller_O1.S caller_O2.S caller_O3.S \
	callee_O0.o callee_O1.o callee_O2.o callee_O3.o \
	caller_O0.o caller_O1.o caller_O2.o caller_O3.o \
	callee_O0.txt callee_O1.txt callee_O2.txt callee_O3.txt \
	caller_O0.txt caller_O1.txt caller_O2.txt caller_O3.txt \

VPATH=. ./asm ./obj ./objdump

CC=clang
CFLAGS=-std=c11 -I. -Wall

# callee
#	asm
callee_O0.S: callee.c
	${CC} ${CFLAGS} -O0 -S -o asm/$@ callee.c

callee_O1.S: callee.c
	${CC} ${CFLAGS} -O1 -S -o asm/$@ callee.c

callee_O2.S: callee.c
	${CC} ${CFLAGS} -O2 -S -o asm/$@ callee.c

callee_O3.S: callee.c
	${CC} ${CFLAGS} -O3 -S -o asm/$@ callee.c

#	obj
callee_O0.o: callee.c
	${CC} ${CFLAGS} -O0 -c -o obj/$@ callee.c

callee_O1.o: callee.c
	${CC} ${CFLAGS} -O1 -c -o obj/$@ callee.c

callee_O2.o: callee.c
	${CC} ${CFLAGS} -O2 -c -o obj/$@ callee.c

callee_O3.o: callee.c
	${CC} ${CFLAGS} -O3 -c -o obj/$@ callee.c

#	objdump
callee_O0.txt: obj/callee_O0.o
	objdump -d -C $< > objdump/$@

callee_O1.txt: obj/callee_O1.o
	objdump -d -C $< > objdump/$@

callee_O2.txt: obj/callee_O2.o
	objdump -d -C $< > objdump/$@

callee_O3.txt: obj/callee_O3.o
	objdump -d -C $< > objdump/$@

# caller
#	asm
caller_O0.S: caller.c
	${CC} ${CFLAGS} -O0 -S -o asm/$@ caller.c

caller_O1.S: caller.c
	${CC} ${CFLAGS} -O1 -S -o asm/$@ caller.c

caller_O2.S: caller.c
	${CC} ${CFLAGS} -O1 -S -o asm/$@ caller.c

caller_O3.S: caller.c
	${CC} ${CFLAGS} -O3 -S -o asm/$@ caller.c

#	obj
caller_O0.o: caller.c
	${CC} ${CFLAGS} -O0 -c -o obj/$@ caller.c

caller_O1.o: caller.c
	${CC} ${CFLAGS} -O1 -c -o obj/$@ caller.c

caller_O2.o: caller.c
	${CC} ${CFLAGS} -O1 -c -o obj/$@ caller.c

caller_O3.o: caller.c
	${CC} ${CFLAGS} -O3 -c -o obj/$@ caller.c

#	objdump
caller_O0.txt: obj/caller_O0.o
	objdump -d -C $< > objdump/$@

caller_O1.txt: obj/caller_O1.o
	objdump -d -C $< > objdump/$@

caller_O2.txt: obj/caller_O2.o
	objdump -d -C $< > objdump/$@

caller_O3.txt: obj/caller_O3.o
	objdump -d -C $< > objdump/$@

# misc

clean:
	rm -f asm/*.S obj/*.o objdump/*.txt
