output: menu.o yomu.o algorithms.o main.o
	g++ -std=c++11 menu.o yomu.o algorithms.o main.o -o output

menu.o: menu.cpp
	g++ -g -c -std=c++11 menu.cpp

yomu.o: yomu.cpp
	g++ -g -c -std=c++11 yomu.cpp

algorithms.o: algorithms.cpp
	g++ -g -c -std=c++11 algorithms.cpp

main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp

clean:
	rm *.o output
