//Defining a header file for testing classes.
#include <iostream>
#include <string>

using namespace std;

class Word {
	private:
		string speak;
	public:
		void set(const string& speak) const;
		char get() const;
};
