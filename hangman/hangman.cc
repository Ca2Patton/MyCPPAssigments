#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool running = true;
int MAXTRIES = 5;
char letters[15];
string word = "Strings!";

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
		cout << "You have " << MAXTRIES << " left." << endl;
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
	cout << "Press ENTER/RETURN to quit\n";
	cin.get();
	running = 0;
	return;
}

void Lose()
{
	cout << "A shame, you were unable to guess correctly. The word was " << word << "\n";
	cout << "Press ENTER/RETURN to quit.\n";
	cin.get();
	running = 0;
	return;
}
