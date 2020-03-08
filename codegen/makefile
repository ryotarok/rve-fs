all: jitc01_O0 jitc01_O1 jitc01_O2 jitc01_O3 \
	 objdump_jitc01_O0.txt objdump_jitc01_O1.txt objdump_jitc01_O2.txt objdump_jitc01_O3.txt \

VPATH += ./bin ./objdump

CC=clang
CFLAGS=-std=c11 -I.

jitc01_O0: jitc01.c
	${CC} ${CFLAGS} -O0 -o bin/$@ jitc01.c

jitc01_O1: jitc01.c
	${CC} ${CFLAGS} -O1 -o bin/$@ jitc01.c

jitc01_O2: jitc01.c
	${CC} ${CFLAGS} -O2 -o bin/$@ jitc01.c

jitc01_O3: jitc01.c
	${CC} ${CFLAGS} -O3 -o bin/$@ jitc01.c

objdump_jitc01_O0.txt: jitc01_O0
	objdump -d -C bin/jitc01_O0 > objdump/$@

objdump_jitc01_O1.txt: jitc01_O1
	objdump -d -C bin/jitc01_O1 > objdump/$@

objdump_jitc01_O2.txt: jitc01_O2
	objdump -d -C bin/jitc01_O2 > objdump/$@

objdump_jitc01_O3.txt: jitc01_O3
	objdump -d -C bin/jitc01_O3 > objdump/$@

clean:
	rm -f bin/*
