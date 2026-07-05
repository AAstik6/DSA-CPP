#include<iostream>
using namespace std;

int main() {

  int arr[5];
  cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

  cout << arr[2] << endl;
  cout << arr[4] << endl;
  arr[3] = 100;
  cout << arr[3];
  return 0;
}