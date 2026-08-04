#include<iostream>
#include<map>
#include<stack>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<int> st;

        for (int i=0; i<n; i++) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for (int i=0; i<n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else { // closing bracket
                if (st.empty()) return false;
                else if (st.top() == '(' && s[i] == ')') st.pop();
                else if (st.top() == '[' && s[i] == ']') st.pop();
                else if (st.top() == '{' && s[i] == '}') st.pop();
                else return false;
            }
        }
        if (st.empty()) return true;
        else return false;
    }
};

// 739. Daily Temperatures.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;

        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                ans[i] = 0;
            }

            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};

// 503. Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n,0);

        for (int i=n-1; i>=0; i--) {
            st.push(nums[i]);
        }

        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (st.empty()) ans[i] = -1;
            else if (st.top() > nums[i]) ans[i] = st.top();
            st.push(nums[i]);
        }
        return ans;

    }
};

// 1209. Remove All Adjacent Duplicates in String II
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;

        for (int i=0; i<n; i++) {
            if (st.empty()) st.push({s[i], 1});
            else if (!st.empty() && st.top().first != s[i]) st.push({s[i], 1});
            else if (!st.empty() && st.top().second == k-1) st.pop();
            else if (!st.empty() && st.top().first == s[i]) st.top().second++;
        }
        string res = "";
        while (!st.empty()) {
            pair<char, int> p = st.top();
            while (p.second > 0) {
                res.push_back(p.first);
                p.second--;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        stack<ListNode*> st;

        while (temp != NULL) {
            while (!st.empty() && st.top()->val < temp->val) {
                st.pop();
            }
            st.push(temp);
            temp = temp->next;
        }
        ListNode* next = nullptr;
        while (!st.empty()) {
            ListNode* node = st.top();
            node->next = next;
            next = node;
            st.pop();
        }
        return next;
    }
};