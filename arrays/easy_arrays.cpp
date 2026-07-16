#include<iostream>
#include<set>
#include <unordered_map>
using namespace std;

void largest_element(int arr[], int n) {
  int largest = arr[0];
  for(int i=0; i<=n-1; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  cout << largest;
}

void second_largest_element(int arr[], int n) {
  // For largest element.
  int largest = arr[0];
  for (int i=0; i<n; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
    // For second largest element.
    int second = -1;
    for (int i=0; i<n; i++) {
      if (arr[i] > second && arr[i]!=largest) {
        second = arr[i];
      }
    }
    cout << second;
}

void check_sorted(int arr[], int n) {
  for (int i=1; i<n; i++) {
    if (arr[i-1] <= arr[i]) {
    }
    else {
      cout << "false";
    }
  }
  cout << "true";
}

void remove_duplicates(int arr[], int n) {
  int i=0;
  for (int j=0; j<n; j++) {
    if (arr[j]!=arr[i]) {
      arr[i+1] = arr[j];
      i++;
    }
  }
  cout << "number of unique elements:", i+1;
}

// rotate an array by one place to the left
void left_rotate_by_one_place (int arr[], int n) {
  int temp = arr[0];
  for (int i=1; i<n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n-1] = temp;
  //printing rotated array
  for (int i=0; i<=n-1; i++) {
  cout << arr[i];
  }
}

void rotate_by_k_places(int arr[], int n, int k) {
  //optimal solution
  reverse(arr, arr+k);
  reverse(arr+k, arr+n);
  reverse(arr, arr+n);
}

void place_zeroes_to_last (int arr[], int n) {
  // brute force
  vector<int> temp;
  for (int i=0; i<n; i++){
    if (arr[i] != 0) {
      temp.push_back(arr[i]);
    }
  }
  int nz = temp.size();
  for (int i=0; i<nz; i++) {
    arr[i] = temp[i];
  }
  for (int i=nz; i<=n-1; i++) {
    arr[i] = 0;
  }

  //optimal solution
  int j = -1;
  for (int i=0; i<n; i++) {
    if (arr[i] = 0) {
      j = i;
    }
    break;
  }
  for (int i=j+1; i<n; i++) {
    if (arr[i] != 0) {
      swap(arr[i], arr[j]);
    }
    j++;
  }
}

int linear_search (int arr[], int n, int target) {
  for(int i=0; i<n; i++) {
    if (arr[i] == target) {
      return i;
    }
}
return -1;
}

void num_appearing_one_time (int arr[], int n) {
  unordered_map<int, int> hashMap;
  //storing the elements in the hash map with key as the array num and value as the frequency.
  for (int i=0; i<=n-1; i++) {
    hashMap[arr[i]]++;
  }
  //iterating the hash_map for the single num.
  for (auto it : hashMap) {
    if (it.second == 1) {
      cout << "the single number is:" << it.first << endl;
    }
  }

  // optimal sol:
  int single = 0;
  for (int i=0; i<=n-1; i++) {
    single ^= arr[i];
  }
  cout << "the single number is:" << single << endl;
}

// --> 219. Contains Duplicate II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mpp;
        int n = nums.size();
        int low = 0;
        int high = 0;
        int ans = INT_MAX;

        if (n == 1) return false;

        while (high < n) {
            mpp[nums[high]]++;
            while (mpp[nums[high]] == 2) {
                ans = abs(low - high);
                if (ans <= k) return true;
                mpp[nums[low]]--;
                low++;
            }
            high++;
        }
        return false;
    }
};

int main() {
  int n; 
  cin >> n;
  int arr[n];
  for (int i=0; i<=n-1; i++) {
    cin >> arr[i];
  }
  num_appearing_one_time(arr, n);
}