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