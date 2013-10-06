//Caitlin A. Patton
//ComSci 48 - C++ Part Two
//Giambattista

#include <iostream>
#include <string>

class PhoneNumber { //This class will help the user make a list of phone numbers)
	private:
		int countryCode; //Stores the Country Code e.g. +1
		int areaCode; //Stores Area Code e.g. (925)
		int number; //Stores Number e.g. 754-6978
		char type; //Stores the "type" of number. e.g. 'H' for home, 'B' for business, 'C' for cell.
		int year; //Stores the year the number was added, for some odd reason.
	public:
		PhoneNumber(); //Empty constructor
		PhoneNumber(int ccode, int acode, int num, char line, int year); //Default Constructor
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


PhoneNumber::PhoneNumber(int ccode = 43, int acode = 800, int num = 8675309, char line = 'H', int year = 1981) {
	return PhoneNumber;
}

PhoneNumber::PhoneNumber(int ccode, int acode, int num, char line, int year) {
	return PhoneNumber;
}
PhoneNumber::PhoneNumber(int num, char line = 'B') {
	return PhoneNumber;
}

PhoneNumber::PhoneNumber (int acode, int num, char line = 'C') {
	return PhoneNumber;
}

void PhoneNumber::setCountry(int ccode) {
	cout << "What Year is it?";
	cin >> ccode;
}

void PhoneNumber::setArea(int acode) {
	cout << "What is the area code?";
	cin >> acode;
}

void PhoneNumber::setNumber(int num) {
	cout << "What is the main number?";
	cin >> num;
}

void PhoneNumber::setType(char line) {
	cout << "What is the line type? 'C'ell, 'H'ome, or 'B'usiness?";
	cin >> line;
}

void PhoneNumber::setYear(int year) {
	cout << "What is the current year?";
	cin >> year;
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

int PhoneNumber::getType() const {
	return type;
}

int PhoneNumber::getYear() const {
	return year;
}

bool PhoneNumber::doubleDigits() const {

}

void PhoneNumber::printNumber() const {

}

void PhoneNumber::printPhoneNumberStats() const {

}

int main() {
	PhoneNumber firstNum;
	PhoneNumber secondNum(39, 415, 867666, 'B', 2012);
	PhoneNumber thirdNum(1212121);
	PhoneNumber fourthNum(1234566, 'C');
	PhoneNumber fifthNum(925, 4392181);
	PhoneNumber sixthNum(925, 5512346, 'H');
	firstNum.printNumber();
	firstNum.printPhoneNumberStats();
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

	return 0;
}
