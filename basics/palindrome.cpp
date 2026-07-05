#include<iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  int reverse_num = 0;
  int dup = n;
  while (n>0) {
    int ld = n%10;
    reverse_num = (reverse_num*10)+ld;
    n = n/10;
  }
  if (reverse_num == dup) cout << "true";
  else cout << "false";
}