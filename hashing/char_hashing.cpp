#include<iostream>
using namespace std;

int main () {
  string s;
  cin >> s;

  int hash[25] = {0};
  for (int i=0; i<s.size(); i++) {
    hash[s[i] - 'a'] += 1;
  }

  int q;
  cin >> q;
  for(int i=0; i<q; i++) {
    char c;
    cin >> c;

    //fetch 
    cout << hash[c-'a'] << endl;
  }
  return 0;
}

// we can also take the size of the hash as 256
// then we dont need to subtract the ascii value.