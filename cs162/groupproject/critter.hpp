#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>
#include <vector>
#include <random>


enum CritterDirection { Up = 1, Down = 2, Left = 3, Right = 4 };
class Critter
{
private:
	char bugLetter;		// X in doodlebug class, O in ant class
	int age;		// Increments each step. Used to determine breeding and death
	int row;
	int column;
	bool alreadyMoved;
	void checkPosition(int &rowMove, int &colMove, CritterDirection checkDirection);
public:
	int randDirection(int numDirections);
	void setBugLetter(char);
	char getBugLetter();
	int getAge();
    void setYPosition(int);
    void setXPosition(int);
	CritterDirection nextDirection();
	void setAge(int);
	int getYPosition();
	int getXPosition();
	void breed(Critter***, int &returnRow, int &returnCol, bool &spaceFound);
	void setAlreadyMoved(bool);
	bool getAlreadyMoved();
	Critter(char bugLetter, int row, int column);		// Constructor sets letter and step number variable values
	Critter(char enteredBugLetter)
	{
		age = 0;	// All bugs start at age 0
		alreadyMoved = false;	// Starts as false
		setBugLetter(enteredBugLetter);
	}

    virtual void move(int x, int y, Critter*** c, int z, int w) {};

    friend std::ostream& operator<<(std::ostream&, Critter);

};

#endif
