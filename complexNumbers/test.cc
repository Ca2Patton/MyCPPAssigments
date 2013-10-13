#include <iostream>
#include <complex>



using namespace std;

class Testing {
	private:
		int real, imaginary;
	public:
		Testing () {};
		Testing (int real, int imaginary);
		Testing operator + (Testing);
		void print();
};

Testing::Testing (int r, int i) {
	real      = r;
	imaginary = i;
}

Testing Testing::operator + (Testing number) {
	Testing num;
	num.real      = real      + number.real;
	num.imaginary = imaginary + number.imaginary;
	return (num);
}

void Testing::print() {
	cout << real << "+" << imaginary << "i" << endl;
}

int main() {
	Testing x(2, 8);
	Testing y(1, -1);
	Testing result;
	result = x + y;
	result.print();
	return 0;
}

