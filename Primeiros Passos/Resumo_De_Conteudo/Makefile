all: output
	./output

comandosBasicos: comandosBasicos.c
	gcc -Wall -g comandosBasicos.c -o output
	./output

estruturasDeRepeticao: estruturasDeRepeticao.c
	gcc -Wall -g estruturasDeRepeticao.c -o output
	./output <estruturasDeRepeticao.txt

vetores: vetores.c
	gcc -Wall -g vetores.c -o output
	./output <vetores.txt

struct_prontuario: struct_prontuario.c
	gcc -Wall -g struct_prontuario.c -o output
	./output <struct_prontuario.txt

insertion_sort: insertion_sort.cpp
	g++ -Wall -g insertion_sort.cpp -o output
	./output

quick: quick_sort.cpp
	g++ -Wall -g quick_sort.cpp -o output
	./output <quick_sort.txt

bubble: bubble.cpp
	g++ -Wall -g bubble.cpp -o output

selection: selection.cpp
	g++ -Wall -g selection.cpp -o output

insertion: insertion.cpp
	g++ -Wall -g insertion.cpp -o output

merge: merge.cpp
	g++ -g merge.cpp -o output

clean:
	rm output

#CC = gcc
#CFLAGS = -o -Wall -g

#TARGET = comandosBasicos

#all: $(TARGET)
#$(TARGET): $(TARGET).c
#	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET) 	
#	./$(TARGET) <comandosBasicos.txt