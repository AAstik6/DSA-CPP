#include <iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        int vertex = 0;
        vector<bool> visited(n,false);
        vector<int> res;
        queue<int> qu;

        qu.push(vertex);
        visited[0] = true;

        while (!qu.empty()) {
            int t = qu.front();
            res.push_back(t);
            qu.pop();
            for (int i=0; i<adj[t].size(); i++) {
                int next_vertex = adj[t][i];
                if (visited[next_vertex] == false) {
                    qu.push(next_vertex);
                    visited[next_vertex] = true;
                }
            }
        }
        return res;
    }
};
