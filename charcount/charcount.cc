/**********************************************************************************
*charcount -- A program to quantify the number of characters input by the user.   *
*										  *
*Author: Caitlin A. Patton							  *
*										  *
*Purpose: To count number of characters in a string				  *
*										  *
*										  *
**********************************************************************************/
#include <string>
#include <iostream>

using namespace std;

char line[100];

int main()
{
cout << "Enter any number of numbers and letters: ";
cin.getline(line, sizeof(line));

cout << "The number of characters you entered is: " << strlen(line) << '\n';
return (0);

}
