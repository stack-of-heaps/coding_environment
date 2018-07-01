output: character.o barbarian.o medusa.o bluemen.o harrypotter.o vampire.o yomu.o match.o menu.o main.o
	g++ -std=c++11 character.o barbarian.o medusa.o bluemen.o harrypotter.o vampire.o yomu.o match.o menu.o main.o -o output

character.o: character.cpp
	g++ -c -std=c++11 character.cpp

barbarian.o: barbarian.cpp
	g++ -c -std=c++11 barbarian.cpp

medusa.o: medusa.cpp
	g++ -c -std=c++11 medusa.cpp

bluemen.o: bluemen.cpp
	g++ -c -std=c++11 bluemen.cpp

harrypotter.o: harrypotter.cpp
	g++ -c -std=c++11 harrypotter.cpp

vampire.o: vampire.cpp
	g++ -c -std=c++11 vampire.cpp

yomu.o: yomu.cpp
	g++ -c -std=c++11 yomu.cpp

match.o: match.cpp
	g++ -c -std=c++11 match.cpp

menu.o: menu.cpp
	g++ -c -std=c++11 menu.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

make clean:
	rm *.o output
