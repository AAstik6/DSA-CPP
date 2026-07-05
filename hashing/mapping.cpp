#include <iostream>
#include <map>
using namespace std;

int main () {
  int n;
  cin >> n;
  int arr[n];
  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }
// pre-compute
map<int, int> mpp;
for(int i=0; i<n; i++) {
  mpp[arr[i]]++;
}


  int q;
  cin >> q;
  for(int i=0; i<q; i++) {
    int number;
    cin >> number;
    //fetch
    cout << mpp[number];
  }
}