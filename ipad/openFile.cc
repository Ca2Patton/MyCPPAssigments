#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cerrno>
#include <cstring>

using std::cout;
using std::cin;

std::string get_file_contents(const char *filename)
{
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

int main()
{
	char * file;
	cout << "What file would you like to change?\n";
//	cin.ignore();
	cin >> file;
//	get_file_contents(file);
	cout << file << "\n";
	return 0;

}
