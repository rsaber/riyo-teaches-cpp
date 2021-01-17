#include <iostream>
#include <string>


void changeNumber(int& n)
{
	std::cout << "im inside changeNumber(), the address is " << n << std::endl;
	n = 25;
}

void doSomethingWithAnInt(const int& n)
{
	// writes n to a database...
}

double findDistance(int x, int y)
{
	// pythagoras

	return 100;
}

/*
class Coordinate
{
	int m_x;
	int m_y;

	Coordinate(int x, int y) : m_x(x), m_y(y)
	{
		// maybe do some other stuff
	}

	
		Coordinate bob;
		Coordinate john;
		Coordinate james = bob + john;
	
	void operator+ (const Coordinate& right)
	{
		m_x += right.m_x;
		m_y += right.m_y;
	}

	// a += 8;
};
*/

/*
Lab:

Create a class that holds fractions. Overload +,-,/,* for this new class.

*/

int main()
{
	// Fraction f(1,2);
	// Fraction g(3,4);

	// std::cout << f << g << f+g << std::endl;

	/*
	int bigNumber = 100;	

	std::cout << "bigNumber is " << bigNumber << " and it is stored in " << &bigNumber << std::endl;

	bigNumber = 50;

	std::cout << "bigNumber is " << bigNumber << " and it is stored in " << &bigNumber << std::endl;

	changeNumber(bigNumber);

	std::cout << "bigNumber is " << bigNumber << " and it is stored in " << &bigNumber << std::endl;


	int array[] = {1,2,3,4,5};

	
	    <--4bytes--->
		[1           ][2][3][4][5]
		^              ^
		|              |
		array          array+1
	

	std::cout << array[0] << std::endl;
	std::cout << array[7] << std::endl;

	char string[] = "hello"; // {'h','e','l','l','o'};

    
	    <--1byte--->
		[h          ][e][l][l][o]['\0']
		^            
		|       
		string
									^
									|
									p
	

	
		string = 0x100;
		p = string; p == 0x100
		while (the thing inside p isn't '\0')
		{
			p++; // 
		}
	

	char* p = string;
	while(*p != '\0')
	{
		std::cout << "[" << *p << "]";
		++p;
	}
	std::cout << std::endl;

	std::string myString = "hello";
	myString = "bob";

	std::cout << myString << std::endl;

	*/

	return 0;
}