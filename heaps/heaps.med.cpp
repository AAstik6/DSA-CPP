# include<iostream>
# include<queue>
# include<vector>

using namespace std;


class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int> pq;
        for (int i=0; i<k; i++) {
            pq.push(arr[i]);
        }
        for (int i=k; i<n; i++) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }

    // 215. Kth Largest Element in an Array
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        int n = nums.size();
        for (int i=0; i<k; i++) {
            pq.push(nums[i]);
        }
        for (int i=k; i<n; i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};