all : output
	./output

fila : fila_circ.h fila_circ.c fura_fila.c
	gcc -c fila_circ.c
	gcc -c fura_fila.c
	gcc fila_circ.o fura_fila.o -o output