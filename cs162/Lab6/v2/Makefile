output: dll.o yomu.o menu.o main.o
	g++ -std=c++11 dll.o yomu.o menu.o main.o -o output
dll.o: dll.cpp
	g++ -c -std=c++11 dll.cpp
yomu.o: yomu.cpp
	g++ -c -std=c++11 yomu.cpp
menu.o: menu.cpp
	g++ -c -std=c++11 menu.cpp
main.o: main.cpp
	g++ -c -std=c++11 main.cpp

clean:
	rm *.o output
