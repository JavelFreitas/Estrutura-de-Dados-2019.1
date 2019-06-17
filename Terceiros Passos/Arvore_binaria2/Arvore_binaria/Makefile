all: output
	./output

arv: arvore.c arvore.o arvore.h
	gcc -c arvore.c
	gcc -c prog.c
	gcc arvore.o prog.o -o output
	./output <teste.txt