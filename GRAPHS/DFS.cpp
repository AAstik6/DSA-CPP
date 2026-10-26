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


// 1254. Number of Closed Islands..
class Solution {
public:
    bool isBoundary(int row, int col, int n, int m) {
        if (row == 0 || row == n-1 || col == 0 || col == m-1) return true;
        return false;
    }

    bool isValid(int row, int col, int n, int m) {
        if (row >= n || row < 0 || col >= m || col < 0) return false;
        return true;
    }

    void DFS(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited, vector<int>& x_axis, vector<int>& y_axis, bool& touchesBorder, int n, int m) {
        visited[row][col] = true;

        if (isBoundary(row, col, n, m) == true) touchesBorder = true;

        for (int k=0; k<4; k++) {
            int r = row + x_axis[k];
            int c = col + y_axis[k];

            if (isValid(r, c, n, m) == true && grid[r][c] == 0 && visited[r][c] == false) {
                DFS(grid, r, c, visited, x_axis, y_axis, touchesBorder, n, m);
            }
        }
        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n);
        for (int i=0; i<n; i++) {
            vector<bool> t(m, false);
            visited[i] = t;
        }

        vector<int> x_axis = {1,-1,0,0};
        vector<int> y_axis = {0,0,1,-1};

        int total_islands = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                bool touchesBorder = false;
                if (grid[i][j] == 0 && isBoundary(i, j, n, m) == false && visited[i][j] == false) {
                    DFS(grid, i, j, visited, x_axis, y_axis, touchesBorder, n, m);
                    if (touchesBorder == false) total_islands++;
                }
            }
        }
        return total_islands;
    }
};