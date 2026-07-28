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