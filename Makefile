GCC=gcc
LDFLAGS=-lm -lentrees
LIB=./lib
BIN=./bin
INCLUDE=./include
CFLAGS=-Wall -g
SRC=./src/entrees.c ./src/fichier.c ./src/gnuplot.c ./src/log.c ./src/position.c ./src/main.c
OBJ=$(SRC:.c=.o)
EXEC=./bin/test.exe

all:$(EXEC)

$(EXEC): $(OBJ) $(INCLUDE)/*.h
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ) -I$(INCLUDE) -L$(LIB) $(LIBFLAGS)
	rm $(OBJ) 
	
gnuplot.o: gnuplot.c $(INCLUDE)/gnuplot.h
	$(GCC) $(CFLAGS) -o gnuplot.o -c ./src/gnuplot.c
	
log.o: log.c $(INCLUDE)/log.h
	$(GCC) $(CFLAGS) -o log.o -c ./src/log.c
	
clean:
	rm $(EXEC)
