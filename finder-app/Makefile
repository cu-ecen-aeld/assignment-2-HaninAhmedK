#_*_Makefile_*_

CC = gcc

ifdef CROSS_COMPILE
	CC = $(CROSS_COMPILE)gcc
endif

all: writer


writer: writer.o
	$(CC)  writer.o -o writer

writer.o: writer.c
	$(CC) -c writer.c

clean:
	rm -f *.o writer

