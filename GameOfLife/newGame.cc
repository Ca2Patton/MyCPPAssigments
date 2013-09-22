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
const char bounds = 'O';
char gameboard[ROWS][COLS];

bool load_data(string filename, char board[][COLS]);
void print_board(char board[][COLS]);
void evolve(char board[][COLS]);

int main(){
	char board[ROWS][COLS];
	string filename;
	cout << "Enter Filename: \n";
	cin >> filename;
	cout << endl;

	if (!load_data(filename, board)) {
		cout << "File not found. \n\n";
		return 1;
	}
	cout << endl;
	for (int loop = 0; loop < 10; loop++) {
		print_board(board);
		evolve(board);
	}
	return 0;
}

bool load_data(string filename, char board[][COLS]) {
	ifstream my_file;
	my_file.open (filename.c_str());
	if (!my_file) return false;

	for (int row = 0; row <ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			my_file >> board[row][col];
		}
	}
	my_file.close();
	return true;
}

void print_board(char board[][COLS]) {
	for (int row = 1; row <= ROWS-2; row++) {
		for (int col = 1; col <= COLS -2; col++) {
			cout << board[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

void evolve(char board[][COLS]) {
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			int neighbors = 0;
			//Skipping over the 'O's
			if (board[row][col] == bounds) {
				continue;
			}
			//Left Top Across
			if (board[row - 1][col - 1] == alive) {
				neighbors++;
			}
			//Up
			if (board[row - 1][col] == alive) {
				neighbors++;
			}
			//Right Top Across
			if (board[row - 1][col + 1] == alive) {
				neighbors++;
			}
			//Left
			if (board[row][col - 1] == alive) {
				neighbors++;
			}
			//Right
			if (board[row][col + 1] == alive) {
				neighbors++;
			}
			//Left Bottom Across
			if (board[row + 1][col - 1] == alive) {
				neighbors++;
			}
			//Right Bottom Across
			if (board[row + 1][col + 1] == alive) {
				neighbors++;
			}
			//Down
			if (board[row + 1][col] == alive) {
				neighbors++;
			}

			//Apply four rules of life
			//if cell neighbors has < 2 kill it
			//if cell 2||3 neighbors remains alive
			//if cell > 3 neighbors dies due to over population
			//if cell is dead and has exactly three neighbors, resurrect it

			if (board[row][col] == alive && neighbors < 2) {
				board[row][col] = dead;
			}
			else if (board[row][col] == alive && neighbors == 2 || neighbors == 3) {
				board[row][col] = alive;
			}
			else if (board[row][col] == alive && neighbors > 3) {
				board[row][col] = dead;
			}
			else if (board[row][col] == dead && neighbors == 3) {
				board[row][col] = alive;
			}


		}
	}
}
