#include <iostream>

using namespace std;


class Complex {
	private:
		int real; //Real number
		int imag; //Imaginary number
	public:
		Complex();
		Complex(int real, int imag);
		Complex operator + (const Complex&);
		Complex operator - (const Complex&);
		Complex operator * (const Complex&);
		Complex operator - ();
};

Complex::Complex() {
	real = realNum;
	imag = imaginaryNum;
}

Complex::Complex(int real) {
}

Complex::Complex(int real, int imag) {
}

Complex Complex::operator + (const Complex&) {
	return Complex(real + imag);
}

Complex Complex::operator - (const Complex&) {
}

Complex Complex::operator * (const Complex&) {
}



int main() {
	Complex a = Complex(1, 2);

	cout << a << endl;
	return 0;
}
