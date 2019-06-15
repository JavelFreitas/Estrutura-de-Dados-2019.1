all: output
	./output

func: funcional.cpp funcional.o
	g++ -Wall -c funcional.cpp
	g++ funcional.o -o output
	./output

emb: embaralhar.c embaralhar.o
	gcc -c embaralhar.c
	gcc embaralhar.o -o output
	./output