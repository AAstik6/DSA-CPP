#include<iostream>
using namespace std;

void printName (string name) {
  cout << "hey" << " " << name;
}
int main() {
  string name;
  cin >> name;
  printName(name);

  string name2;
  cin >> name2;
  printName(name2);
  return 0;
}