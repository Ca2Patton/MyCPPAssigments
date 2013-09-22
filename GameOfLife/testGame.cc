#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int ROWS = 12;
const int COLS = 30;
const int B_ROWS(10);
const int B_COLS(28);
const char alive = 'X';
const char dead = '.';
char gameBoard[ROWS][COLS];

bool load_data(string filename, char board[][COLS]);
void print_board(char board[][COLS]);
void change_board(char board[][COLS]);
void change_state(char board[][COLS]);

int main() {
	char board[ROWS][COLS];
	string filename;
	cout << "Enter filename: \n";
	cin >> filename;
	cout << endl;

	if (!load_data(filename, board)) {
		cout << "File not found. \n\n";
		return 1;
	}
	cout << endl;
	for (int loop = 0; loop < 10; loop++) {
		change_state(board);
		print_board(board);
		change_board(board);
	}

	return 0;
}

bool load_data(string filename, char board[][COLS]) {
	ifstream my_file;
	my_file.open (filename.c_str());
	if (!my_file) return false;

	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			my_file >> board[r][c];
		}
	}
	my_file.close();

	return true;
}

void print_board (char board[][COLS]) {
	for (int row = 1; row <= ROWS-2; row++) {
		for (int col = 1; col <= COLS - 2; col++) {
			cout << board[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

void change_state (char board[][COLS]) {
	for (int row = 0; row < ROWS; row++) {
		for (int c = 0; c < COLS; r++) {
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
			if (board[r][c +1] == alive) {
				neighbors++;
			}
			if (board[r + 1][c - 1] == alive) {
				neighbors++;
			}
			if (board[r + 1][c +1] == alive) {
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
	

void change_board(char board[][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			board[r][c]=gameBoard[r][c];
		}
	}
}
