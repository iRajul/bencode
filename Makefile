
CC=gcc
CFLAGS= -Wall -pedantic -std=c++14


SRCDIRS = src
INCDIRS = include

SOURCES  := $(wildcard $(SRCDIR)/*.cxx)
INCLUDES := $(wildcard $(INCDIR)/*.hxx)


default : bencode.a

bencode.a : bencode.o 

bencode.o : decode.o items.o visitor.o
	$(CC) $(CFLAGS) -o bencode.o decode.o items.o visitor.o

decode.o : $(SRCDIR)/decode.cxx



