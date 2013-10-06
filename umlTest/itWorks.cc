#include <iostream>
#include <string>

using namespace std;

string spoken;

string word() {
   cout << "Fill the string ";
   cin >> spoken;
   return spoken;
}

int main (){
  cout << word() << endl;
  return 0;
}

