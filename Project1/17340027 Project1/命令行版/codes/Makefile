FlAGS := -std=c++11 -w

Calculator:main.o Calculator.o
	g++ $(FlAGS) -o Calculator main.o Calculator.o

main.o:main.cpp Calculator.hpp
	g++ $(FlAGS) -c main.cpp

Calculator.o:Calculator.cpp Calculator.hpp
	g++ $(FlAGS) -c Calculator.cpp
	
clean:
	rm Calculator main.o Calculator.o