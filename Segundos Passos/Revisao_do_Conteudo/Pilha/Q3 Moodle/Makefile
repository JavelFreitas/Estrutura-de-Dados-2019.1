all: output
	./output

pilha: pilha.c dec_pra_bin.c pilha.h
	gcc -c pilha.c
	gcc -c dec_pra_bin.c
	gcc dec_pra_bin.o pilha.o -o output

clear: output
	rm output