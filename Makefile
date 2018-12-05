GCC=gcc
LDFLAGS=-lm
LIB=./lib
BIN=./bin
INCLUDE=./include
CFLAGS=-Wall -g
SRC=./src/entrees.c ./src/fichier.c ./src/gnuplot.c ./src/log.c ./src/position.c ./src/main.c ./src/param.c
OBJ=$(SRC:.c=.o)
EXEC=./bin/attracteur.out
EXEC_F=./bin/attracteur.exe

all:$(EXEC)

$(EXEC): $(OBJ) $(INCLUDE)/*.h
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ) -I$(INCLUDE) -L$(LIB) $(LIBFLAGS)
	chmod u+rx bin/*.sh
	mv $(EXEC) $(EXEC_F)
	rm $(OBJ) 

entrees.o: entrees.c $(INCLUDE)/entrees.h
	$(GCC) $(CFLAGS) -o entrees.o -c ./src/entrees.c	
	
fichier.o: fichier.c $(INCLUDE)/fichier.h
	$(GCC) $(CFLAGS) -o fichier.o -c ./src/fichier.c
	
gnuplot.o: gnuplot.c $(INCLUDE)/gnuplot.h
	$(GCC) $(CFLAGS) -o gnuplot.o -c ./src/gnuplot.c
	
log.o: log.c $(INCLUDE)/log.h
	$(GCC) $(CFLAGS) -o log.o -c ./src/log.c

position.o: position.c $(INCLUDE)/position.h
	$(GCC) $(CFLAGS) -o position.o -c ./src/position.c

main.o: main.c $(INCLUDE)/main.h
	$(GCC) $(CFLAGS) -o main.o -c ./src/main.c
	
clean:
	rm $(EXEC_F)
	rm src/*.o