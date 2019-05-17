all: output
	./output

pilha: pilha.cpp prog.cpp pilha.h
	c++ -c pilha.cpp
	c++ -c prog.cpp
	c++ prog.o pilha.o -o output

clear: output
	rm output