#include <iostream>
#include "Word.hh"
using namespace std;
Word spoken;

int main() {
	spoken.set("Bacon Bits");
	cout << spoken.get();
	return 0;
}
