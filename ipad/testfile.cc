#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

int main()
{
using namespace std;
locale loc;
string strInput;
ifstream inf("sampleText.txt");
    if (!inf)
{
	    cerr << "Uh oh, file could not be opened for reading!" << endl;
	    exit(1);
}

    while (inf)
{
   getline(inf, strInput);
}

string text = strInput; 
cout << text << endl;

int count = text.size();
if (count > 0)
{
	text[0] = toupper(text[0], loc);
}
for(int i = 1; i < count; i++)
{
	if (isspace(text[i - 1], loc))
		text[i] = toupper(text[i], loc);
	else
		text[i] = tolower(text[i]);
}
cout << text << endl;
   return 0;
			     
}

