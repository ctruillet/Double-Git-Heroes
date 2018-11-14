GCC=gcc
LDFLAGS=-lm -lentrees
LIB=../lib
BIN=../bin
INCLUDE=../include
CFLAGS=-Wall -g
SRC=entrees.c fichier.c gnuplot.c log.c position.c main.c
OBJ=$(SRC:.c=.o)
EXEC=test.exe

all:$(EXEC)

$(EXEC): $(OBJ) $(INCLUDE)/*.h
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ) -I$(INCLUDE) -L$(LIB) $(LIBFLAGS)
	
gnuplot.o: gnuplot.c $(INCLUDE)/gnuplot.h
	$(GCC) $(CFLAGS) -o gnuplot.o -c gnuplot.c
	
log.o: log.c $(INCLUDE)/log.h
	$(GCC) $(CFLAGS) -o log.o -c log.c
	
clean:
	rm $(EXEC) $(OBJ)
