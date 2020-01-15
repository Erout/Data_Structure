flags := -std=c++11 -w
hash:main.o hash.o
	g++ $(flags) -o hash main.o hash.o

main.o: main.cpp hash.hpp
	g++ $(flags) -c main.cpp

hash.o:hash.cpp hash.hpp
	g++ $(flags) -c hash.cpp

clean:
	rm hash hash.o main.o