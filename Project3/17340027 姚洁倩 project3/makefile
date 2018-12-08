flags := -std=c++11 -w
huffman:main.o huffman.o
	g++ $(flags) -o huffman main.o huffman.o

main.o:main.cpp huffman.hpp
	g++ $(flags) -c main.cpp

huffman.o:huffman.cpp huffman.hpp
	g++ $(flags) -c huffman.cpp

clean: 
	rm huffman huffman.o main.o