#include<iostream>
using namespace std;

bool ispalin(int i, string s) {
  if (i>=s.size()/2) return true;
  if (s[i]!=s[s.size()-i-1]) return false;
  return ispalin(i+1,s);
}

int main () {
  string s = "madam";
  cout << ispalin(0,s);
}