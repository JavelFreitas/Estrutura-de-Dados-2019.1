all: output
	./output

t: teste.cpp
	g++ -Wall -g teste.cpp -o output
	./output

bubble_decrescente: bubble_decrescente.cpp
	g++ -Wall -g bubble_decrescente.cpp -o output
	./output

insercao_de_alunos: insercao_de_alunos.cpp
	g++ -Wall -g insercao_de_alunos.cpp -o output
	./output <insercao.txt

clean:
	rm output

#CC = gcc
#CFLAGS = -o -Wall -g

#TARGET = comandosBasicos

#all: $(TARGET)
#$(TARGET): $(TARGET).c
#	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET) 	
#	./$(TARGET) <comandosBasicos.txt
# abcdefgh: abcdefgh.cpp
# 	gcc -Wall -g  abcdefgh.cpp -o output
# 	./output <testes