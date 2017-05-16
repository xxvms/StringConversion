// StringConversion.cpp : Defines the entry point for the console application.
//
/*

conversion of the C type string and String Objects

*/
#include "stdafx.h"
#include <iostream>
#include <string.h>						// for strcpy()

class String
{
	static const int SZ = 80;			// size of all String objects
	char str[SZ];						// holds a C String
public:
	String()							//NO arguments constructor
	{
		str[0] = '\0';
	}
	String(char s[])					// 1 argument string constructor
	{
		strcpy_s(str, s);					// converts C-string to String
	}
	void display() const				// display String constatnt as reading does not require any changes to the data.
	{
		std::cout << str << std::endl;
	}
	operator char*()					// conversion operator
	{
		return str;						// converts String to C-string
	}

};

   
int main()
{
	String s1;							// will use no argument constructor
										// create and initialize C-string
	char xstr[] = "Joyeux Noel! ";

	s1 = xstr;							// use 1 argument constructor to convert C-string to String
	s1.display();						// display String

	String s2 = "Bonne Annee!";			// uses 1 argument constructor to initialize String
	std::cout << static_cast<char*>(s2); // use conversion operator to convert String to C-string before sending to << operator 
	
	std::cout << std::endl;

	system("pause");
    return 0;
}

