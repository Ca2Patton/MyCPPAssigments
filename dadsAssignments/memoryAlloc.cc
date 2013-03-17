#include <iostream>    
#include <new>          

using namespace std;

int main () {
  cout << "Attempting to allocate 500 KB...";
  char* p = new (nothrow) char [500];
  if (p==0) cout << "Failed!\n";
  else {
    cout << "Succeeded!\n";
    delete[] p;
  }
  return 0;
}
