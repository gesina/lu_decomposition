cc = gcc
CFLAGS = -Wall -Werror -O2 -std=c99 -lm -g 
LCFLAGS = $(CFLAGS)
OCFLAGS = $(CFLAGS) -c
MAINBIN = lu_decomposition

DEPFILE = lu_decomposition.deps

#objects
OBJECTF += main.o
OBJECTF += print.o
OBJECTF += input.o
OBJECTF += lu_decomposition.o
OBJECTF += substitutions.o


all: deps main

deps: *.h *.c
	$(cc) -MM *.c > $(DEPFILE)

main: ${OBJECTF}
	$(cc) $(CFLAGS) -o $(MAINBIN) *.o

%.o: %.c %.h
	$(cc) $(OCFLAGS) -o $*.o $*.c
 

include $(DEPFILE)
