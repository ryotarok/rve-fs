all: \
	callee_O0.S callee_O1.S callee_O2.S callee_O3.S \
	caller_O0.S caller_O1.S caller_O2.S caller_O3.S \
	callee_O0.o callee_O1.o callee_O2.o callee_O3.o \
	caller_O0.o caller_O1.o caller_O2.o caller_O3.o \
	obj_callee_O0.txt obj_callee_O1.txt obj_callee_O2.txt obj_callee_O3.txt \
	obj_caller_O0.txt obj_caller_O1.txt obj_caller_O2.txt obj_caller_O3.txt \
	exe_O0 exe_O1 exe_O2 exe_O3 \
	exe_O0.txt exe_O1.txt exe_O2.txt exe_O3.txt \

VPATH=. ./asm ./obj ./bin ./objdump

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
# 		obj.txt
obj_callee_O0.txt: obj/callee_O0.o
	objdump -d -C $< > objdump/$@

obj_callee_O1.txt: obj/callee_O1.o
	objdump -d -C $< > objdump/$@

obj_callee_O2.txt: obj/callee_O2.o
	objdump -d -C $< > objdump/$@

obj_callee_O3.txt: obj/callee_O3.o
	objdump -d -C $< > objdump/$@

#		exe.txt
exe_O0.txt: bin/exe_O0
	objdump -d -C $< > objdump/$@

exe_O1.txt: bin/exe_O1
	objdump -d -C $< > objdump/$@

exe_O2.txt: bin/exe_O2
	objdump -d -C $< > objdump/$@

exe_O3.txt: bin/exe_O3
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

#	obj objdump
obj_caller_O0.txt: obj/caller_O0.o
	objdump -d -C $< > objdump/$@

obj_caller_O1.txt: obj/caller_O1.o
	objdump -d -C $< > objdump/$@

obj_caller_O2.txt: obj/caller_O2.o
	objdump -d -C $< > objdump/$@

obj_caller_O3.txt: obj/caller_O3.o
	objdump -d -C $< > objdump/$@

# bin
#	exe
exe_O0: main.c callee_O0.o caller_O0.o
	${CC} ${CFLAGS} -O0 -o bin/$@ main.c obj/callee_O0.o obj/caller_O0.o

exe_O1: main.c callee_O1.o caller_O1.o
	${CC} ${CFLAGS} -O1 -o bin/$@ main.c obj/callee_O1.o obj/caller_O1.o

exe_O2: main.c callee_O2.o caller_O2.o
	${CC} ${CFLAGS} -O2 -o bin/$@ main.c obj/callee_O2.o obj/caller_O2.o

exe_O3: main.c callee_O3.o caller_O3.o
	${CC} ${CFLAGS} -O3 -o bin/$@ main.c obj/callee_O3.o obj/caller_O3.o

#	exe objdump
exe_caller_O0.txt: bin/exe_O0
	objdump -d -C $< > objdump/$@

exe_caller_O1.txt: bin/exe_O1
	objdump -d -C $< > objdump/$@

exe_caller_O2.txt: bin/exe_O2
	objdump -d -C $< > objdump/$@

exe_caller_O3.txt: bin/exe_O3
	objdump -d -C $< > objdump/$@

# misc

clean:
	rm -f asm/*.S obj/*.o bin/*
