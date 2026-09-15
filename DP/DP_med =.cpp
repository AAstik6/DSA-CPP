#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
  public:
    int MaxAns(vector<int>& val, vector<int>& wt, int W, int i, int n, vector<vector<int>>& dp) {
        if (i >= n) return 0;
        
        if (dp[i][W] != -1) return dp[i][W];
        
        if (W - wt[i] >= 0) {
            int p1 = val[i] + MaxAns(val,wt,W-wt[i],i+1,n,dp); // adding to knapsack
            int p2 = MaxAns(val,wt,W,i+1,n,dp); // skip by choice
            dp[i][W] = max(p1,p2);
            return max(p1,p2);
        }
        
        else if (W - wt[i] < 0) {
            int p3 = MaxAns(val,wt,W,i+1,n,dp); // skip by condition.
            dp[i][W] = p3;
            return p3;
        }
        return 0;
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        vector<vector<int>> dp(n);
        for (int i=0; i<=n-1; i++) {
            vector<int> t(W+1,-1);
            dp[i] = t;
        }
        
        int maxProfit = MaxAns(val,wt,W,0,n,dp);
        return maxProfit;
        
    }
};

// 0/1 knapsack problem with tabulation.
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // knapsack with tabulation.
        int n = val.size();
        int m = wt.size();
        
        vector<vector<int>> dp_memory(n+1);
        for (int i=0; i<=n; i++) {
            vector<int> t(W+1);
            dp_memory[i] = t;
        }
        for (int j=0; j<=W; j++) {
            dp_memory[n][j] = 0; // filled the last row with 0.
        }
        
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<=W; j++) {
                if (j - wt[i] < 0) { // without choice...
                    dp_memory[i][j] = dp_memory[i+1][j];
                }
                else if (j - wt[i] >= 0) { // with choice...
                    dp_memory[i][j] = max(val[i] + dp_memory[i+1][j - wt[i]], dp_memory[i+1][j]);
                }
            }
        }
        return dp_memory[0][W];
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int MaxProfit(TreeNode*& temp, map<TreeNode*,vector<int>>& HashMemory, bool take) {
        if (temp == NULL) return 0;

        if (HashMemory[temp][take] != -1) return HashMemory[temp][take];

        if (take == 1) {
            int m1 = temp->val + MaxProfit(temp->left, HashMemory, 0) + MaxProfit(temp->right, HashMemory, 0);
            int m2 = MaxProfit(temp->left, HashMemory, 1) + MaxProfit(temp->right, HashMemory, 1);

            HashMemory[temp][take] = max(m1,m2);
            return max(m1,m2);
        }
        else if (take == 0) {
            int m3 = MaxProfit(temp->left, HashMemory, 1) + MaxProfit(temp->right, HashMemory, 1);

            HashMemory[temp][take] = m3;
            return m3;
        }
        return 0;
    }

    void memo(TreeNode* root, map<TreeNode*, vector<int>>& HashMemory) {
        if (root == NULL) return;
        memo(root->left, HashMemory);
        HashMemory[root] = {-1,-1};
        memo(root->right, HashMemory);
        return;
    }

    int rob(TreeNode* root) {
        map<TreeNode*, vector<int>> HashMemory;
        memo(root, HashMemory);

        bool take = true;
        TreeNode* temp = root;
        int ans = MaxProfit(temp,HashMemory,take);
        return ans;
    }
};


// GFG -- subset sum problem..
class Solution {
  public:
    int CheckValid(vector<int>& arr, int sum, bool& ans, int i, int n, vector<vector<int>>& dp_memory) {
        if (sum == 0) return ans = true;
        
        if (i>=n) return 0;
        
        if (dp_memory[i][sum] != -1) return dp_memory[i][sum];
        
        if (arr[i] > sum) {
            int a1 = CheckValid(arr, sum, ans, i+1, n, dp_memory);
            
            dp_memory[i][sum] = a1;
            return a1;
        }
        else if (arr[i] <= sum) {
            int a2 = arr[i] + CheckValid(arr, sum - arr[i], ans, i+1, n, dp_memory);
            int a3 = CheckValid(arr, sum, ans, i+1, n, dp_memory);
            
            dp_memory[i][sum] = a2+a3;
            return a2+a3;
        }
        return 0;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        bool ans = false;
        int n = arr.size();
        int m = sum;
        int i = 0;
        
        // for memoization.
        vector<vector<int>> dp_memory(n);
        for (int i=0; i<n; i++) {
            vector<int> t(m+1,-1);
            dp_memory[i] = t;
        }
        
        CheckValid(arr, sum, ans, i, n, dp_memory);
        return ans;
    }
};