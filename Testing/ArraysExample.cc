//Caitlin A. Patton
//September 14th, 2013

#include <iostream>
using namespace std;

int main() {
	const int NUM_ROWS = 5; //Number of Rows
	const int NUM_COLS = 5; //Number of Columns
	int numbers[NUM_ROWS][NUM_COLS] =
	{{2, 7, 9, 6, 4},
	 {6, 1, 8, 9, 4},
	 {4, 3, 7, 2, 9},
	 {9, 9, 0, 3, 1},
	 {6, 2, 7, 4, 1}};
	cout << "Table Contents: \n";
	for (int counter = 0; counter < NUM_ROWS; counter++)
	{
		for (int nCount = 0; nCount < NUM_COLS; nCount++)
		{
			cout << numbers[counter][nCount] << ' ';
		}
		cout << endl;
	}
	cout << numbers[1][3] << endl;
	return 0;
}
