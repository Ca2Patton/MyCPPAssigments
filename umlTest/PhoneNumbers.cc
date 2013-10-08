//Caitlin A. Patton
//ComSci 48 - C++ Part Two
//Giambattista

#include <iostream>
#include <string>
using namespace std;

class PhoneNumber 
{ //This class will help the user make a list of phone numbers)
	private:
		int countryCode; //Stores the Country Code e.g. +1
		int areaCode; //Stores Area Code e.g. (925)
		int number; //Stores Number e.g. 754-6978
		char type; //Stores the "type" of number. e.g. 'H' for home, 'B' for business, 'C' for cell.
		int year; //Stores the year the number was added, for some odd reason.
	public:
		PhoneNumber(); //Empty constructor
		PhoneNumber(int ccode, int acode, int num, char line, int year);
		PhoneNumber(int num, char line = 'B');
		PhoneNumber(int acode, int num, char line = 'C');
		void setCountry(int ccode);
		void setArea(int acode);
		void setNumber(int num);
		void setType(char line);
		void setYear(int yr);
		int getCountry() const;
		int getArea() const;
		int getNumber() const;
		char getType() const;
		int getYear() const;
		bool doubleDigits() const;
		void printNumber() const;
		void printPhoneNumberStats() const;
};

//The Default Constructor
PhoneNumber::PhoneNumber() {
	setCountry(43);
	setArea(800);
	setNumber(8675309); 
	setType('H');
	setYear(1981);
}

//Fill out the Phone Number class
/* 
PhoneNumber::PhoneNumber(int ccode, int acode, int num, char line, int year) {
}

PhoneNumber::PhoneNumber(int num, char line) {
}

PhoneNumber::PhoneNumber (int acode, int num, char line) {
}
*/
void PhoneNumber::setCountry(int ccode) {
	countryCode = ccode;
}

void PhoneNumber::setArea(int acode) {
	areaCode = acode;
}

void PhoneNumber::setNumber(int num) {
	number = num;	
}

void PhoneNumber::setType(char line) {
	type = line;
}

void PhoneNumber::setYear(int yyyy) {
	year = yyyy;
}

int PhoneNumber::getCountry() const {
	return countryCode;
}

int PhoneNumber::getArea() const {
	return areaCode;
}

int PhoneNumber::getNumber() const {
	return number;
}

char PhoneNumber::getType() const {
	return type;
}

int PhoneNumber::getYear() const {
	return year;
}

bool PhoneNumber::doubleDigits() const {
return true;
}

void PhoneNumber::printNumber() const {
	cout << number << endl;
}

void PhoneNumber::printPhoneNumberStats() const {
return;
}

int main() {

	PhoneNumber firstNum;
/*	PhoneNumber secondNum(39, 415, 867666, 'B', 2012);
	PhoneNumber thirdNum(1212121);
	PhoneNumber fourthNum(1234566, 'C');
	PhoneNumber fifthNum(925, 4392181);
*///	PhoneNumber sixthNum(925, 5512346, 'H');
	firstNum.printNumber();
/*	firstNum.printPhoneNumberStats();
	secondNum.printNumber();
	secondNum.printPhoneNumberStats();
	thirdNum.printNumber();
	thirdNum.printPhoneNumberStats();
	fourthNum.printNumber();
	fourthNum.printPhoneNumberStats();
	fifthNum.printNumber();
	fifthNum.printPhoneNumberStats();
	sixthNum.printNumber();
	sixthNum.printPhoneNumberStats();
*/
	return 0;
}
