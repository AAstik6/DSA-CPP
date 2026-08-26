#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    void DFS(vector<vector<int>>& adj, vector<int>& res,
    int node, vector<bool>& visited) {
        res.push_back(node);
        visited[node] = true;
        
        for (int i=0; i<adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (visited[neighbor] == false) {
                DFS(adj, res, neighbor, visited);
            }
        }
        return;
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> res;
        vector<bool> visited(n, false);
        int node = 0;
        DFS(adj, res, node, visited);
        return res;
    }
};