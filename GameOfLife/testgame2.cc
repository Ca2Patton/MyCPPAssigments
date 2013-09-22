#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

void inputFile();
bool array();
char changeArray();
char Board();

const int ROWS = 12;
const int COLS = 30;
const int BOARD_ROWS(10);
const int BOARD_COLS(28);
ifstream myfile;
string filename;
char alive = 'X';
char dead = '.';
char board[BOARD_ROWS][BOARD_COLS];

int main() {
	inputFile();
	if (array()) {
		for (int i(0); i < 10; i++)
			changeArray();
	}
	else {
		cout << "Error parsing input file" <<endl;
	}
	return 0;
}

void inputFile() {
	cout << "Enter the filename: \n";
	cin >> filename;
	return;
}

bool array() {
	bool ret(false);
	char val;
	int totCnt(BOARD_ROWS*BOARD_COLS);
	myfile.open(filename.c_str());
	if (myfile) {
		for (int r = 0; r < ROWS; r++) {
			for (int c = 0; c < COLS; c++) {
				myfile >> val;
				if (val == dead || val == alive) {
					board[r - 1][c - 1] = val;
					totCnt--;
				}
			}
		}
		if (!totCnt) {
			ret = true;
		}
		myfile.close();
	}
	return ret;
}

char getNextState(char b[BOARD_ROWS][BOARD_COLS], int r, int c) {
	char ret;
	int neighbors = 0;
	if (b[r - 1][c - 1] == alive) {
		neighbors++;
	}
	if (b[r - 1][c] == alive) {
		neighbors++;
	}
	if (b[r - 1][c + 1] == alive) {
		neighbors++;
	}
	if (b[r][c - 1] == alive) {
		neighbors++;
	}
	if (b[r][c + 1] == alive) {
		neighbors++;
	}
	if (b[r + 1][c - 1] == alive) {
		neighbors++;
	}
	if (b[r + 1][c + 1] == alive) {
		neighbors++;
	}
	if (b[r + 1][c] == alive) {
		neighbors++;
	}
