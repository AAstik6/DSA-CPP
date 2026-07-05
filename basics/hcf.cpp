#include<iostream>
using namespace std;

int main () {
  int gcd = 1;
  int n1,n2;
  cin >> n1 >> n2;
  for (int i=0; i<=min(n1,n2); i++) {
    if (n1%i==0 && n2%i==0) {
      gcd = i;
    }
  }
  cout << "the gcd/hcf of the given numbers is:" << gcd;
}