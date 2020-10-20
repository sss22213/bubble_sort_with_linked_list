CC = gcc
SRCDIR = src
BUILDDIR = build
CFLAGS = -g -Wall -std=c11

.PHONY: all clean main bubble_sort.o list.o test

all: clean bubble_sort.o list.o main

main:
	${CC} ${CFLAGS} ${BUILDDIR}/list.o ${BUILDDIR}/bubble_sort.o ${SRCDIR}/main.c -o ${BUILDDIR}/main

bubble_sort.o:
	${CC} ${CFLAGS} -c ${SRCDIR}/bubble_sort.c -o ${BUILDDIR}/bubble_sort.o

list.o:
	${CC} ${CFLAGS} -c ${SRCDIR}/list.c -o ${BUILDDIR}/list.o

clean:
	rm -f ${BUILDDIR}/*.o ${BUILDDIR}/main

test:
	./${BUILDDIR}/main
