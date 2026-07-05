// take two numbers and print its sum.

#include<iostream>
using namespace std;
/*
void print_sum (int num1, int num2) { // --> cout
  cout << "The sum of the numbers is:" << num1 + num2;
}
*/

int sum(int num1, int num2) { // --> return function
  int num3 = num1 + num2;
  return num3;
}
int main() {
  int num1 , num2;
  cin >> num1 >> num2;
  int res = sum(num1,num2);
  cout << res;
  return 0;
}