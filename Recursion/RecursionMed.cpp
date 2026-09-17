#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

// 78. Subsets -- recursion with backtracking.
class Solution {
public:
    void FindSubsets(int start, vector<int>& current, vector<vector<int>>& answer, vector<int>& nums, int n) {
        // base case.
        if (start == n) {
            answer.push_back(current);
            return;
        }
        answer.push_back(current);
        for (int i=start; i<n; i++) {
            current.push_back(nums[i]);
            FindSubsets(i+1, current, answer, nums, n);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> answer;
        int n = nums.size();

        FindSubsets(0, current, answer, nums, n);
        return answer;
    }
};


// 90. Subsets II -- Recursion with backtracking.
class Solution {
public:
    void FindSubsets(int start, vector<int>& current, vector<vector<int>>& answer, vector<int>& nums, int n) {
        // base case.
        if (start == n) {
            answer.push_back(current);
            return;
        }
        answer.push_back(current);
        for (int i=start; i<n; i++) {

            if (i>start && nums[i] == nums[i-1]) continue;
            
            current.push_back(nums[i]);
            FindSubsets(i+1, current, answer, nums, n);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        FindSubsets(0,current,answer,nums,n);
        return answer;
    }
};

// 77. Combinations -- Recursion with backtracking.
class Solution {
public:
    void SolveCombination(int start, vector<int>& current, vector<vector<int>>& answer, int n, int k) {
        // base case - pushes the k size combination into the answer vector.
        if (current.size() == k) {
            answer.push_back(current);
            return;
        }
        
        for (int i=start; i<=n; i++) {
            current.push_back(i);
            SolveCombination(i+1, current, answer, n, k);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> answer;

        SolveCombination(1,current, answer, n, k);
        return answer;
    }
};