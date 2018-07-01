output: building.o person.o student.o instructor.o university.o yomu.o main.o
	g++ -std=c++11 building.o person.o student.o instructor.o university.o yomu.o main.o -o output

university.o: university.cpp
	g++ -c -std=c++11 university.cpp

building.o: building.cpp
	g++ -c -std=c++11 building.cpp

person.o: person.cpp
	g++ -c -std=c++11 person.cpp

student.o: student.cpp
	g++ -c -std=c++11 student.cpp

instructor.o: instructor.cpp
	g++ -c -std=c++11 instructor.cpp

yomu.o: yomu.cpp
	g++ -c -std=c++11 yomu.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp
make clean:
	rm *.o output
	
