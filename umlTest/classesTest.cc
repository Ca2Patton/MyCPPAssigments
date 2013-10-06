#include <iostream>
#include <string>

using namespace std;

class quiteSimple {
	private:
		string simplyData;

	public:
		string word();
};

string quiteSimple::word() {
	cout << "Enter data\n";
	cin >> simplyData;
	return simplyData;
}

int main() {
	quiteSimple spoken;
	cout << spoken.word();
	return 0;
}
