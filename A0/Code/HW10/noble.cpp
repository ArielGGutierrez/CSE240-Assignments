#include "noble.h";
#include <iostream>

// Q2b: Define displayBook() for Noble class (5 points)
// Define the function displayBook() that you declared within the Noble class in the header file
// See expected output in question file.
void Noble::displayBook()
{
	cout << "Book name: " << getName() << endl;
	cout << "Price: " << getPrice() << endl;
	cout << "Library: Noble" << endl;
	cout << endl;
}
// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files
