//Name: Caitlin A. Patton
//Assignment 3: Miles Per Gallon
/*This program will output the number of miles per gallon the car
in the assignment question has traveled.*/

#include <iostream>
using namespace std;

float gallon = 13.0; //Number of gallons of gas the car holds
float milesTraveled = 350.; //Number of miles the car can travel before running out of gas.

float gallon2; //Prompting for User Input of gallons of gas
float milesTraveled2; //Prompting for number of miles car can travel before running out of gas.

int main()
{
	cout << "Example Output: The car's Miles Per Gallon is " << (milesTraveled / gallon) << endl;
	
	cout << "Please input the gas tank size (in gallons) of your car.\n";
	cin >> gallon2;
	cout << "Please input the number of miles your car can travel before running out of gas\n";
	cin >> milesTraveled2;
	cout << "Your estimated Miles Per Gallon is " << (milesTraveled2 / gallon2) << endl;
	
	return(0);
}

