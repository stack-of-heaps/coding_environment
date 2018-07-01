output: board.o ant.o menu.o yomu.o main.o
	g++ board.o ant.o menu.o yomu.o main.o -o output

board.o: board.cpp
	g++ -c board.cpp

ant.o: ant.cpp
	g++ -c ant.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

yomu.o: yomu.cpp
	g++ -c yomu.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o output
