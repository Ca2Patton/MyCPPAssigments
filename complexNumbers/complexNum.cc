//Caitlin A. Patton
//October 20th, 2013
//L. Giambattista
//ComSci 48 - Introduction to C++ Part Two

#include <iostream>

using namespace std;


class Complex {
	private:
		int real; //Real number
		int imag; //Imaginary number
	public:
		Complex(); //Default constructor.
		Complex(int re);
		Complex(int re, int im);
		Complex operator + (const Complex& right) const;
		Complex operator - (const Complex& right) const;
		Complex operator * (const Complex& right) const;
		Complex operator - ();
		bool operator == (const Complex& right);
		friend ostream& operator << (ostream& out, const Complex& right);
};

Complex::Complex() {
	real = 0; //Did not feel like creating "set" and "get" mutators. I'm lazy.
	imag = 0;
}

Complex::Complex(int re) {
	real = re;
}

Complex::Complex(int re, int im) {
	real = re;
	imag = im;
}
//Overloading plus to deal with multiple arguments.
Complex Complex::operator + (const Complex& right) const {
	Complex temp;
	temp.real = real + right.real;
	temp.imag = imag + right.imag;
	return temp;
	
}
//Overloading minus to subtract pairs against other pairs.
Complex Complex::operator - (const Complex& right) const {
	Complex left; //Silly variable names exist because I don't know what else to name them.
	left.real = real - right.real;
	left.imag = imag - right.imag;
	return left;
}
//Overloading the * operator to multiply pairs of numbers against other pairs.
Complex Complex::operator * (const Complex& right) const {
	Complex up;
	up.real= real * right.real;
	up.imag = imag * right.imag;
	return up;
}
//Overloading the unary - operator to display negative numbers without error.
Complex Complex::operator - () {
	Complex foo;
	foo.real = -real;
	foo.imag = -imag;
	return foo;
}

//Using a bool to compare the real/imaginary pairs against each other.
bool Complex::operator == (const Complex& right) {
	Complex test;
	if (test.real == right.real && test.imag == right.imag)
		return true;
	else
		return false;
}

//This is where we overload the << to display our variables properly, otherwise cout doesn't know how
//to display the variables. (I just love segmentation fault: 11
ostream& operator << (ostream& out, const Complex& right) {
	out << right.real << " + " << right.imag << "i";
	return out;
}

int main() {
	Complex first;
	Complex second(-4);
	Complex third(1, -2);
	Complex fourth(-1, 2);
	Complex fifth(3, 0);
	Complex sixth(0, 3);
	Complex seventh(5, 3);
	Complex eighth(6, 10);
	Complex ninth(7, 4);
	Complex tenth(-14, 8);

	cout << endl;

	if (third == fourth)
		cout << "The complex numbers are equal." << endl;
	else
		cout << "The complex numbers are not equal." << endl;
	if (first == first)
		cout << "The complex numbers are equal." << endl;
	else
		cout << "The complex numbers are not equal." << endl;
	if (first == third + fourth)
		cout << "The complex numbers are equal." << endl;
	else
		cout << "The complex numbers are not equal." << endl;
	cout << endl;

	cout << "(" << first << ")" << " + " << "(" << second << ")" << " = " << first + second << endl;
	cout << "(" << first << ")" << " - " << "(" << second << ")" << " = " << first - second << endl;
	cout << "(" << first << ")" << " * " << "(" << second << ")" << " = " << first * second << endl;
	cout << "-(" << second << ")" << " = " << -second << endl;

	cout << endl;

	cout << "(" << third << ")" << " + " << "(" << fourth << ")" << " = " << third + fourth << endl;
	cout << "(" << third << ")" << " - " << "(" << fourth << ")" << " = " << third - fourth << endl;
	cout << "(" << third << ")" << " * " << "(" << fourth << ")" << " = " << third * fourth << endl;
	cout << "-(" << third << ")" << " = " << -third << endl;

	cout << endl;

	cout << "(" << fifth << ")" << " + " << "(" << sixth << ")" << " = " << fifth + sixth << endl;
	cout << "(" << fifth << ")" << " - " << "(" << sixth << ")" << " = " << fifth - sixth << endl;
	cout << "(" << fifth << ")" << " * " << "(" << sixth << ")" << " = " << fifth * sixth << endl;
	cout << "-(" << fifth - sixth << ")" << " = " << -(fifth - sixth) << endl;

	cout << endl;

	cout << "(" << seventh << ")" << " + " << "(" << eighth << ")" << " = " << seventh + eighth << endl;
	cout << "(" << seventh << ")" << " - " << "(" << eighth << ")" << " = " << seventh - eighth << endl;
	cout << "(" << seventh << ")" << " * " << "(" << eighth << ")" << " = " << seventh * eighth << endl;
	cout << "-(" << seventh * eighth << ")" << " = " << -(seventh * eighth) << endl;

	cout << endl;

	cout << "(" << ninth << ")" << " + " << "(" << tenth << ")" << " = " << ninth + tenth << endl;
	cout << "(" << ninth << ")" << " - " << "(" << tenth << ")" << " = " << ninth - tenth << endl;
	cout << "(" << ninth << ")" << " * " << "(" << tenth << ")" << " = " << ninth * tenth << endl;
	cout << "-(" << ninth + tenth << ")" << " = " << -(ninth + eighth) << endl;
	
	cout << endl;

	return 0;
}
