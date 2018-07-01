output: yomu.o recursiveFunctions.o menu.o main.o
	g++ -std=c++11 yomu.o recursiveFunctions.o menu.o main.o -o output

yomu.o: yomu.cpp
	g++ -c -std=c++11 yomu.cpp

recursiveFunctions.o: recursiveFunctions.cpp
	g++ -c -std=c++11 recursiveFunctions.cpp

menu.o: menu.cpp
	g++ -c -std=c++11 menu.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

make clean:
	rm *.o output
