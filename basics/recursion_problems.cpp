#include<iostream>
#include <string>
using namespace std;

int recursion_prob (int n) {
  if (n==0) {
    return 0;
  }
  return n + recursion_prob(n-1);
}
/*
int main () {
  int n;
  cin >> n;
  int sum = 0;
  for (int i=1; i<=n; i++) {
    sum = sum + i;
  }
  cout << sum;
}
*/
void num_sum(int i, int sum) {
  if (i<1) {
    cout << sum;
    return;
  }
  num_sum(i-1,i+sum);
}

int recursion_factorial (int n) {
  if (n==0) {
    return 1;
  }
  return n * recursion_factorial(n-1);
}

void reverse_arr(int i, int arr[], int n) {
  if (i>=n/2) return;
  swap(arr[i],arr[n-i-1]);
  reverse_arr(i+1,arr,n);
}

bool isPalindrome(int i, string s) {
  if (i>=s.size()/2) return true;
  if (s[i]!=s[s.size()-i-1]) return false;
  return isPalindrome(i+1,s);
}
int main () {
  int n;
  cin >> n;
  int arr[n];
  for (int i=0; i<n; i++) cin >> arr[i];
  reverse_arr(0,arr,n);
  for (int i=0; i<n; i++) cout << arr[i];
  return 0;
}
