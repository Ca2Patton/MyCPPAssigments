#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

//Caitlin Ann Patton
//COMSC48
//C++ Part Two

using namespace std;

bool running = true;
int MAXTRIES = 5;
char letters[15];
string word = "strings";

void Reveal();
void Lose();
void Win();

int main() {
	cout << "Welcome To Hangman.\n You have " << MAXTRIES << " left. Please, begin!\n";
	cout << "_______\n";
	char guess;
	while(running) {
		cout << "Enter a letter: ";
		cin >> guess;
		guess = tolower(guess);
		bool correct = 0;
		for (int counter = 0; counter < word.length(); ++counter)
		{
			if(guess == word[counter])
			{
				letters[counter] = guess;
				correct = 1;
			}
		}
		if(correct == 0) --MAXTRIES;
		cout << "You have " << MAXTRIES << " guesses left." << endl;
		correct = 0;


		 Reveal();

		 if(MAXTRIES <= 0) Lose();
		 if(letters == word) Win();


	}
	return 0;
}

void Reveal()
{
	for(int counter = 0; counter < word.length(); ++counter)
	{
		if(letters[counter] == word[counter]) cout << word[counter];
		else cout << "_";
	}
	cout << "\n";
	return;
}

void Win()
{
	cout << "Good job, you win!\n";
	running = 0;
	return;
}

void Lose()
{
	cout << "A shame, you were unable to guess correctly. The word was " << word << "\n";
	running = 0;
	return;
}
