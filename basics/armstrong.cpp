#include<iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  int dup = n;
  int sum = 0;

  while (n>0) {
    int ld = n%10;
    n = n/10;
    sum = sum + (ld*ld*ld);
  }
  if (sum == dup) cout << "the number is an armstrong number.";
  else cout << "the number is not an armstrong number.";
}