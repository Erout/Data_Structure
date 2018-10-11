flags := -std=c++11 -w
StackCal:main.o StackCal.o
	g++ $(flags) -o StackCal main.o StackCal.o

main.o:main.cpp StackCal.h
	g++ $(flags) -c main.cpp

StackCal.o:StackCal.cpp StackCal.h
	g++ $(flags) -c StackCal.cpp

clean: 
	rm StackCal StackCal.o main.o

