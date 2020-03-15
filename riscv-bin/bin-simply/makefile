TARGET=a.out.bin

CC=riscv64-unknown-elf-gcc
CFLAGS=-I. -std=c11 -O0 -Wall -Wextra
LD=riscv64-unknown-elf-ld
OBJCOPY=riscv64-unknown-elf-objcopy
OBJCOPYFLAGS= \
	-I elf64-littleriscv \
	-j .text
	# -j .rodata \
	# -j .srodata.cst4 \
	# -j .text.startup \
	# -j .data \

OBJDUMP=riscv64-unknown-elf-objdump
HEXDUMP=hexdump

all: ${TARGET}

LINKERSCRIPT=test.ld
OBJS=start.o main.o

${TARGET}: ${OBJS}
	${LD} ${LDFLAGS} -T${LINKERSCRIPT} ${OBJS}
	${OBJCOPY} ${OBJCOPYFLAGS} a.out -O binary $@
	${OBJDUMP} -D a.out > a.out.objdump.txt
	${HEXDUMP} a.out.bin > a.out.hexdump.txt

clean:
	rm -f ${TARGET} ${OBJS} a.out

.S.o:
	${CC} ${CFLAGS} -c -o $@ $<

.c.o:
	${CC} ${CFLAGS} -c -o $@ $<
