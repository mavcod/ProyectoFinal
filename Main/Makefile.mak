#archivo que permite la compilación de forma ordenada

CC=gcc
CFLAGS:-pedantic -Wall

all: principal

principal: Main.c funciones.c loadBMP.c
	$(CC) Main.o funciones.o loadBMP.o -o principal
 
Main.o: Main.c
	$(CC) $(CFLAGS) Main.c

funciones.o: funciones.c
	$(CC) $(CFLAGS) funciones.c

loadBMP.o: loadBMP.c
	$(CC) $(CFLAGS) loadBMP.c

clean:
	rm -f *o principal