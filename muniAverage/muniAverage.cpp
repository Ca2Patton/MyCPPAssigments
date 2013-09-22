//Caitlin Ann Patton
//muniAverage Assignment 4
//Introduction to C++ Part One
/* Survey data about Muni riders and create a summary of the data. */

#include <iostream>
using namespace std;


int main()
{

//Variables
char muniLine;		//The Muni Line Surveyed
int daySurveyed; 	//The number of days the line was surveyed for.
int numberRiders; 	//The number of riders counted by the survey.
float averageRider;

	cout << "Which Muni line did you survey?\n";
	cin >> muniLine;
	cout << "How many days did you survey the Muni line?\n";
	cin >> daySurveyed;
	cout << "How many riders were counted by the survey?\n";	
	cin >> numberRiders;

	averageRider = static_cast<float>(numberRiders) / daySurveyed;
	cout << "According to the survey, an average of " << averageRider  << " people rode the " << muniLine << " per day.\n";
	

return 0;
}
