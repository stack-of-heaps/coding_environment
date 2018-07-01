output: queue.o yomu.o menu.o main.o
	g++ -std=c++11 queue.o yomu.o menu.o main.o -o output
queue.o: queue.cpp
	g++ -c -g -std=c++11 queue.cpp
yomu.o: yomu.cpp
	g++ -c -g -std=c++11 yomu.cpp
menu.o: menu.cpp
	g++ -c -g -std=c++11 menu.cpp
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

clean:
	rm *.o output
