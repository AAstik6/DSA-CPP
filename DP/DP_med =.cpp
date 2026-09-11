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