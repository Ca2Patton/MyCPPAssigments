#include <iostream>
using namespace std;
	
	int counter = 0;
	int numbers[100];

int main()
{
	while (counter <= 100)
	{
		if (counter % 5 == 0)
		{
			numbers[counter] = 0;
	
		}
		else (numbers[counter] = counter);
	cout << numbers[counter] << endl;	
	++counter;
	}

return 0;
}
