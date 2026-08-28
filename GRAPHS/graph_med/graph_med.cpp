#include<iostream>
#include<vector>
using namespace std;


// 200. Number of Islands
class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if (i>=n || i<0 || j>=m || j<0) {
            return false;
        }
        return true;
    }

    void DFS(int i, int j, int n, int m, vector<vector<char>>& grid,
    vector<vector<bool>>& visited, vector<int>& x_axis, vector<int>& y_axis) {
        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            int row = i + x_axis[k];
            int col = j + y_axis[k];

            if (isValid(row, col, n, m) == true && visited[row][col] == false
                && grid[row][col] == '1') {
                    
                DFS(row, col, n, m, grid, visited, x_axis, y_axis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n);
        for (int i=0; i<n; i++) {
            vector<bool> t(m, false);
            visited[i] = t;
        }

        vector<int> x_axis(4);
        vector<int> y_axis(4);

        for(int i=0; i<4; i++) {
            if (i == 0) {
                x_axis[i] = 1;
                y_axis[i] = 0;
            }
            else if (i == 1) {
                x_axis[i] = -1;
                y_axis[i] = 0;
            }
            else if (i == 2) {
                x_axis[i] = 0;
                y_axis[i] = 1;
            }
            else if (i == 3) {
                x_axis[i] = 0;
                y_axis[i] = -1;
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    DFS(i, j, n, m, grid, visited, x_axis, y_axis);
                    res++;
                }
            }
        }
        return res;
    }
};

// 994. Rotting Oranges
class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if (i>=n || i<0 || j>=m || j<0) {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int min_time = 0;
        int fresh = 0;
        queue<pair<int,int>> qu;

        int x_axis[4] = { 1 , -1 , 0 , 0}; // for up and down shift
        int y_axis[4] = { 0 , 0 , 1 , -1 }; // for left and right shift.

        int n = grid.size();
        int m = grid[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 2) {
                    qu.push({i,j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while(!qu.empty() && fresh > 0) {
            min_time++;
            int qsize = qu.size();
            while(qsize != 0) {
                pair<int,int> p = qu.front();
                qu.pop();
                for (int k=0; k<4; k++) {
                    int row = p.first + x_axis[k];
                    int col = p.second + y_axis[k];
                    if (isValid(row, col, n, m) == true && grid[row][col] == 1) {
                        qu.push({row,col});
                        fresh--;
                        grid[row][col] = 0;
                    }
                }
                qsize--;
            }
        }
        if (fresh > 0) return -1;
        return min_time;
    }
};