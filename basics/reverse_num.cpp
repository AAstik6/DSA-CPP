#include<iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  int reverse_num = 0;
  while (n>0) {
    int lasdigi = n%10;
    reverse_num = (reverse_num*10)+lasdigi;
    n = n/10;
  }
cout << reverse_num;
}