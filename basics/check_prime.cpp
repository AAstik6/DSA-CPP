#include<iostream>
using namespace std;


int main () {
  int n;
  cin >> n;
  int counter = 0;
  for (int i=0; i<=n; i++) {
    if (n%i==0) {
      counter = counter + 1;
    }
  }
  if (counter == 2) {
    cout << "it is a prime number";
  }
  else cout << "not a prime number";
  
  return 0;
}