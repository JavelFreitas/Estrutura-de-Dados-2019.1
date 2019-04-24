all: output
	./output

pilha: pilha.cpp pilha.h prog.cpp
	g++ -c pilha.cpp
	g++ -c prog.cpp
	g++ prog.o pilha.o -o output

aleatorio: q4_aleatorio.cpp pilha_enc_limite.cpp pilha.h
	g++ -c q4_aleatorio.cpp 
	g++ -c pilha_enc_limite.cpp
	g++ pilha_enc_limite.o q4_aleatorio.o -o output

