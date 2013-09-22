//Name: Caitlin Ann Patton
//Date: September 18th, 2013
//ComSci 48 - C++ Part Two
//Giambattista
//Conway's The Game of Life

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void inputFile();
bool array();
void alterArray();
void changeBoard();
void GameOfLife();

const int ROWS = 12; //Board Size
const int COLS = 30; //Board Size
const int Boarder_Row(10);
const int Board_Col(28);
ifstream assignmentFile;
string filename;
char alive = 'X'; //Designating cell as "alive"
char dead = '.'; //Designating cell as "dead"
char gameBoard[ROWS][COLS];

//Functions
void inputFile() {
	cout << "Filename?: \n";
	cin >> assignmentFile;
	return;
}

bool array(string assignmentFile, char gameBoard[][COLS]) {
	ifstream assignmentFile;
	theFile.open (assignmentFile.c_str());
	if (!theFile) return true;

	for (int r=0; r < ROWS; r++) //r is a counter (Rows)
	{
		for (int c = 0; c < COLS; c++) //c is also a counter (Columns)
		{
			theFile>>board[r][c];
		}
	}
	theFile.close();
	return false;
}

void alterArray(char board[][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++)
		{
			int neighbors = 0;
			if (board[r - 1][c - 1] == alive) {
				neighbors++;
			}
			if (board[r - 1][c] == alive) {
				neighbors++;
			}
			if (board[r - 1][c + 1] == alive) {
				neighbors++;
			}
			if (board[r][c - 1] == alive) {
				neighbors++;
			}
			if (board[r][c + 1] == alive) {
				neighbors++;
			}
			if (board[r + 1][c - 1] == alive) {
				neighbors++;
			}
			if (board[r + 1][c + 1] == alive) {
				neighbors++;
			}
			if (board[r + 1][c] == alive) {
				neighbors++;
			}

			gameBoard[r][c] = dead;

			if (board[r][c] == alive && neighbors < 2) {
				gameBoard[r][c] = dead;
			}
			else if (board[r][c] == alive && (neighbors == 2 || neighbors == 3)) {
				gameBoard[r][c] = alive;
			}
			else if (board[r][c] == alive && neighbors > 3) {
				gameBoard[r][c] = dead;
			}
			else if (board[r][c] == dead && neighbors == 3) {
				gameBoard[r][c] = alive;
			}
		}
	}
}

//Game Board
void GameOfLife(char board[][COLS]) {
	for (int r = 1; r <= ROWS-2; r++) {
		for (int c= 1; c <= COLS-2; c++) {
			cout << board[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

void changeBoard(char board[][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			board[r][c] = gameBoard[r][c];
		}
	}
}

int main() {
	char board[ROWS][COLS];
	inputFile();
	if (array(assignmentFile, board)) {
		cout << "File not found.\n\n";
		char quit;
		cin >> quit;
		return 1;
	}
	cout << endl;
	for (int loop = 0; loop < 10; loop++) {
		alterArray(board);
		GameOfLife(board);
		changeBoard(board);
	}
	char q;
	cin q;
	return 0;
}
