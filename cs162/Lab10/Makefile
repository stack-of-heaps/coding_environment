output: fibR.o fibNR.o main.o
	g++ -std=c++11 fibR.o fibNR.o main.o -o output

fibR.o: fibR.cpp
	g++ -c -g -std=c++11 fibR.cpp

fibNR.o: fibNR.cpp
	g++ -c -g -std=c++11 fibNR.cpp
	
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

clean:
	rm *.o output
