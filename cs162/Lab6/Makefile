output: node.o dll.o yomu.o menu.o main.o
	g++ -std=c++11 menu.o node.o dll.o yomu.o main.o -o output
menu.o: menu.cpp
	g++ -c -std=c++11 menu.cpp
node.o: node.cpp
	g++ -c -std=c++11 node.cpp
dll.o: dll.cpp
	g++ -c -std=c++11 dll.cpp
yomu.o: yomu.cpp
	g++ -c -std=c++11 yomu.cpp
main.o: main.cpp
	g++ -c -std=c++11 main.cpp

clean:
	rm *.o output
