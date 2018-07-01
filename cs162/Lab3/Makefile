output: die.o loadedDie.o menu.o yomu.o game.o main.o
	g++ -std=c++11 die.o loadedDie.o menu.o yomu.o game.o main.o -o output

die.o: die.cpp
	g++ -std=c++11 -c die.cpp

loadedDie.o: loadedDie.cpp
	g++ -std=c++11 -c loadedDie.cpp

menu.o: menu.cpp
	g++ -std=c++11 -c menu.cpp

yomu.o: yomu.cpp
	g++ -std=c++11 -c yomu.cpp

game.o: game.cpp
	g++ -std=c++11 -c game.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o output
