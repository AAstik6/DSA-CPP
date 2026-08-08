# include<iostream>
# include<queue>
# include<vector>
# include<map>

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

    // 347. Top K Frequent Elements
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct cmp {
            bool operator() (pair<int, int>& a, pair<int,int>& b) {
                if (a.first != b.first) {
                    return a.first > b.first; // min heap
                }
                else {
                    return a.second > b.second; // min heap
                }
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        map<int, int> mpp;
        vector<int> res;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }
        for (auto i:mpp) {
            int ele = i.first;
            int freq = i.second;
            pair<int, int> curr_pair = {freq, ele};
            if (pq.size() < k) {
                pq.push(curr_pair);
            }
            else if (curr_pair.first > pq.top().first) {
                pq.pop();
                pq.push(curr_pair);
            }
            else continue;
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    // 973. K Closest Points to Origin
    public:
    map<int, int> cal_dist(vector<vector<int>>& points) {
        int n = points.size();
        map<int, int> mpp;

        for (int i=0; i<n; i++) {
            int dist = (points[i][0] - 0)*(points[i][0] - 0) +
            (points[i][1] - 0)*(points[i][1] - 0);

            mpp[i] = dist;
        }
        return mpp;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct cmp {
            bool operator () (pair<int,int>& a, pair<int,int>& b) {
                if (a.first != b.first) {
                    return a.first < b.first; // max heap
                }
                else {
                    return a.second < b.second; // max heap
                }
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        map<int,int> hash_map = cal_dist(points);
        vector<vector<int>> res;

        for (auto i:hash_map) {
            int distance = i.second;
            int index = i.first;

            pair<int,int> dist_pair = {distance,index};
            if (pq.size() < k) {
            pq.push(dist_pair);
            }
            else if (dist_pair.first < pq.top().first) {
            pq.pop();
            pq.push(dist_pair);
            }
            else continue;
        }
        while (!pq.empty()) {
            int index = pq.top().second;
            res.push_back(points[index]);
            pq.pop();
        }
        return res;
    }

    // 767. Reorganize String
    string reorganizeString(string s) {
        struct cmp {
            bool operator () (pair<int,char>& a, pair<int, char>& b) {
                if (a.first != b.first) {
                    return a.first < b.first; // max heap
                }
                else {
                    return a.second < b.second; // max heap
                }
            }
        };

        map<char,int> mpp;
        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> pq;
        int n = s.size();

        for (int i=0; i<n; i++) {
            mpp[s[i]]++;
        }
        for (auto i:mpp) {
            int freq = i.second;
            char letter = i.first;
            pair<int,char> element = {freq,letter};
            pq.push(element);
        }
        string res = "";
        int seat = 0;
        while (!pq.empty()) {
            pair<int,char> data_1 = pq.top();
            pq.pop();
            if (res.size() == 0 || res[seat-1] != data_1.second) {
                res.push_back(data_1.second);
                seat++;
                data_1.first--;
                if (data_1.first > 0) pq.push(data_1);
            }
            else {
                if (pq.empty()) return "";

                pair<int,char> data_2 = pq.top();
                pq.pop();
                res.push_back(data_2.second);
                seat++;
                data_2.first--;
                if (data_2.first > 0) pq.push(data_2);
                pq.push(data_1);
            }
        }
        return res;
    }

    // 1337. The K Weakest Rows in a Matrix
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        struct cmp {
            bool operator () (pair<int,int>& a, pair<int,int>& b) {
                if (a.first != b.first) {
                    return a.first < b.first;
                }
                else {
                    return a.second < b.second;
                }
            }
        };
        map<int,int> mpp;
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
        
        int n = mat.size();
        int m = mat[0].size();
        for (int i=0; i<n; i++) {
            int num_zero = 0;
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 1) {
                    num_zero++;
                }
            }
            mpp[i] = num_zero;
        }
        for (auto i:mpp) {
            int num_sol = i.second;
            int index = i.first;
            pair<int,int> data = {num_sol,index};
            if (pq.size() < k) pq.push(data);
            else if (data.first < pq.top().first) {
                pq.pop();
                pq.push(data);
            }
            else continue;
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }

    // 502. IPO -> Hard question DO IT AGAIN...
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        for (int i=0; i<n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        priority_queue<int> pq;
        sort(projects.begin(), projects.end());
        int index = 0;
        while (k > 0) {
            int m = projects.size();
            while (index < m) {
                if (projects[index].first > w) break;
                pq.push(projects[index].second);
                index++;
            }
            if (pq.empty()) return w;
            w+= pq.top();
            pq.pop();
            k--;
        }
        return w;
    }

    // merge k sorted arrays. GFG.
    public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        class Node {
        public:
            int value;
            int row;
            int col;
            Node (int v, int r, int c) {
                value = v;
                row = r;
                col = c;
            }
        };
        struct cmp {
            bool operator ()(const Node& a, const Node& b) {
                return a.value > b.value; // min heap with 3 vals.
            }
        };
        
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<Node,vector<Node>, cmp> pq;
        for (int i=0; i<n; i++) {
            pq.push({mat[i][0], i, 0});
        }
        vector<int> res;
        while (!pq.empty()) {
            Node top_ele = pq.top();
            pq.pop();
            int min_val = top_ele.value;
            int row = top_ele.row;
            int col = top_ele.col;
            res.push_back(min_val);
            if (col == m-1) continue;
            pq.push({mat[row][col+1], row, col+1});
        }
        return res;
    }
};