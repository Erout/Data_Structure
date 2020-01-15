flags := -std=c++11 -w
graph:main.o graph.o
	g++ $(flags) -o graph main.o graph.o

main.o: main.cpp graph.hpp
	g++ $(flags) -c main.cpp

graph.o:graph.cpp graph.hpp
	g++ $(flags) -c graph.cpp

clean:
	rm graph graph.o main.o