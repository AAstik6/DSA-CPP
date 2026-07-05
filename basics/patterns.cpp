#include<iostream>
using namespace std;

int main () {
/*
PATTERN 1 
  for (int i = 0; i<5; i++) {
    for (int j = 0; j<5; j++) {
    cout << "*";
  }
  cout << endl;
}

PATTERN 2
for (int i = 0; i<5; i++){
  for (int j = 0; j<=i; j++) {
    cout << "*";
  }
  cout << endl;
}

PATTERN 3
for (int i=1; i<=5; i++) {
  for (int j=1; j<=i; j++) {
    cout << j;
  }
  cout << endl;
}

PATTERN 4
for (int i=1; i<=5; i++) {
  for (int j=1; j<=i; j++) {
    cout << i;
  }
  cout<< endl;
}

PATTERN 5
int n;
cin >> n;
for (int i=1; i<=n; i++) {
  for (int j=1; j<=n-i+1; j++) {
    cout << "*";
  }
  cout << endl;
}

PATTERN 6 
 int n;
 cin >> n;
 for (int i=1; i<=n; i++) {
  for (int j=1; j<=n-i+1; j++) {
    cout << j;
  }
  cout << endl;
 }

 PATTERN 9
int n;
cin >> n;
for (int i=0; i<n; i++) {
  for (int j=1; j<=n-i-1; j++) {
    cout << " ";
  }
  for (int j=1; j<=2*i+1; j++) {
    cout << "*";
  }
  for (int j=1; j<=n-i-1; j++) {
    cout << " ";
  }
  cout << endl; 
}
for(int i=0; i<n; i++) {
  for (int j=0; j<i; j++) {
    cout << " ";  
  }
  for (int j=0; j<2*n-(2*i+1); j++) {
    cout << "*";
  }
  for(int j=0; j<i; j++) {
    cout << " ";
  }
  cout << endl;
}
*/
int n;
cin >> n;

for (int i=1; i<=2*n-1; i++) {
  if (i>n) i=2*n-i;
  for (int j=1; j<=i; j++) {
    cout << "*";
  }
  cout << endl;
}
}