output: animal.o tiger.o turtle.o penguin.o yomu.o zoo.o main.o
	g++ -std=c++11 animal.o tiger.o turtle.o penguin.o yomu.o zoo.o main.o -o output
animal.o: animal.cpp
	g++ -c -std=c++11 animal.cpp

tiger.o: tiger.cpp
	g++ -c -std=c++11 tiger.cpp

turtle.o: turtle.cpp
	g++ -c -std=c++11 turtle.cpp
	
penguin.o: penguin.cpp
	g++ -c -std=c++11 penguin.cpp

yomu.o: yomu.cpp
	g++ -c -std=c++11 yomu.cpp

zoo.o: zoo.cpp
	g++ -c -std=c++11 zoo.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

make clean:
	rm *.o output	
