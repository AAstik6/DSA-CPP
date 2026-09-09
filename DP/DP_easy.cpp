#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

// climbing stairs -- 70
class Solution {
public:
    int WaysToClimb(int i, int& n, map<int,int>& dp) {
        if (i == n) return 1;
        if (i > n) return 0;

        if (dp.find(i) != dp.end()) return dp[i];

        int a1 = WaysToClimb(i+1,n,dp);
        int a2 = WaysToClimb(i+2,n,dp);

        dp[i] = a1+a2;
        return a1+a2;
    }

    int climbStairs(int n) {
        int i = 0;
        map<int,int> dp;
        int ans = WaysToClimb(i,n,dp);
        return ans;
    }
};


// 198 house robber.
class Solution {
public:
    int maxProfit(vector<int>& nums, vector<vector<int>>& track, int i, int free, int& n) {
        if (i >= n) return 0;
        
        if (track[i][free] != -1) return track[i][free];
        
        if (free == 0) return maxProfit(nums,track,i+1,1,n);
        int p1 = nums[i] + maxProfit(nums,track,i+1,0,n);
        int p2 = maxProfit(nums,track,i+1,1,n);

        track[i][free] = max(p1,p2);

        return max(p1,p2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> track(n);
        for (int i=0; i<n; i++) {
            vector<int> t(2,-1);
            track[i] = t;
        }
        int i = 0;
        int free = 1;

        int ans = maxProfit(nums,track,i,free,n);
        return ans;
    }
};