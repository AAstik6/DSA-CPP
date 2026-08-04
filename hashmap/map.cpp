#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> have;
        int n = s.size();
        int cnt = 0;

        for (int i=0; i<n; i++) {
            have[s[i]]++;
        }
        bool odd = false;
        for (auto i:have) {
            int val = i.second;
            if (val%2 == 0) cnt+= val;
            else if (val%2 == 1) odd = true;
        }
        if (odd == false) return cnt;
        else {
            for (auto i:have) {
                int val = i.second;
                if (val%2 == 1) cnt+= val-1;
            }
        }
        cnt++;
        return cnt;
    }
};

class Solution {
public:
    int compare(map<char,int> have, map<char,int> need) {
        int res = INT_MAX;
        for (auto i:need) {
            char c = i.first;
            int mpp_need = i.second;
            int mpp_have = have[c];
            int times = mpp_have/mpp_need;
            res = min(res, times);
        }
        return res;
    }
    int maxNumberOfBalloons(string text) {
        map<char, int> have;
        map<char, int> need;
        int m = text.size();

        string s = "balloon";
        int n = s.size();
        for (int i=0; i<n; i++) {
            need[s[i]]++;
        }
        for (int i=0; i<m; i++) {
            have[text[i]]++;
        }
        int res = compare(have, need);
        return res;
    }

};