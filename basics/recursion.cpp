#include<iostream>
using namespace std;
/*
void give_name(int i,int n) {
  if (i>n) {
    return;
  }
  cout << "DSA" << endl;
  give_name(i+1,n);
}

int main() {
  int n;
  cin >> n;
  give_name(1,n);
}

void reverse_num(int i, int n) {
  if (i<1) {
    return;
  }
  cout << i;
  reverse_num(i-1,n);
}
int main () {
  int n;
  cin >> n;
  reverse_num(n,n);
}
*/
void backtrack(int i,int n) {
  if (i>n){
    return;
  }
  backtrack(i+1,n);
  cout << i;
}
int main () {
  int n;
  cin >> n;
  backtrack(1,n);
}