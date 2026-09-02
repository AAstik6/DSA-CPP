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
        int n = grid.size( );
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

// 547. number of provinces
class Solution {
public:
    void DFS(int i, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
        visited[i] = true;
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                DFS(j, isConnected, visited, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, isConnected, visited, n);
                res++;
            }
        }
        return res;
    }
};

// GFG -- cycle in undirected graph
class Solution {
  public:
    void DFS(vector<vector<int>>& adj_list, vector<bool>& visited,
            int vertex, int parent, bool& cycle) {
        
        visited[vertex] = true;
        for(int i=0; i<adj_list[vertex].size(); i++) {
            int neigh = adj_list[vertex][i];
            if (visited[neigh] == true && neigh != parent) cycle = true;
            else if (visited[neigh] == false) DFS(adj_list, visited, neigh, vertex, cycle);
        }
        return;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here

        // adj_list
        vector<vector<int>> adj_list(V);
        for (int i=0; i<edges.size(); i++) {
            vector<int> edge = edges[i];
            int source = edge[0];
            int destination = edge[1];
            adj_list[source].push_back(destination);
            adj_list[destination].push_back(source);
        }
        // visited list
        int n = adj_list.size();
        vector<bool> visited(n, false);
        
        bool cycle = false;
        for (int i=0; i<n; i++) {
            if (visited[i] == false) {
                DFS(adj_list, visited, i, -1, cycle);
            }
        }
        
        return cycle;
    }
};

// Undirected Graph Cycle
class Solution {
  public:
    void DFS(int vertex, vector<bool>& visited, vector<bool>& path,
            vector<vector<int>>& adj_list, bool& cycle) {
        
        visited[vertex] = true;
        path[vertex] = true;
        
        for (int i=0; i<adj_list[vertex].size(); i++) {
            int neigh = adj_list[vertex][i];
            if (visited[neigh] == true && path[neigh] == true) cycle = true;
            else if (visited[neigh] == false) DFS(neigh, visited, path, adj_list, cycle);
        }
        path[vertex] = false;
        return;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj_list(V);
        for (int i=0 ; i<edges.size(); i++) {
            vector<int> edge = edges[i];
            int source = edge[0];
            int destination = edge[1];
            adj_list[source].push_back(destination);
        }
        
        int n = adj_list.size();
        vector<bool> visited(V, false);
        vector<bool> path(V, false);
        
        bool cycle = false;
        for (int i=0; i<n; i++) {
            if (visited[i] == false && path[i] == false) {
                DFS(i, visited, path, adj_list, cycle);
            }
        }
        return cycle;
        
    }
};

// Topological Sort - GFG
class Solution {
  public:
    void BFS(vector<int>& res, vector<vector<int>>& adj_list,
            vector<int>& inDegree, queue<int>& qu) {
                
        while (!qu.empty()) {
            int vertex = qu.front();
            res.push_back(vertex);
            qu.pop();
            for (int i=0; i<adj_list[vertex].size(); i++) {
                int neigh = adj_list[vertex][i];
                inDegree[neigh]--;
                if (inDegree[neigh] == 0) {
                    qu.push(neigh);
                }
            }
        }
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> res;
        vector<int> inDegree(V);
        
        // bulding the adj_list
        vector<vector<int>> adj_list(V);
        for (int i=0; i<edges.size(); i++) {
            vector<int> edge = edges[i];
            int source = edge[0];
            int destination = edge[1];
            adj_list[source].push_back(destination);
            inDegree[destination]++;
        }
        
        queue<int> qu;
        int n = inDegree.size();
        for (int i=0; i<n; i++) {
            if (inDegree[i] == 0) qu.push(i);
        }
        BFS(res, adj_list, inDegree, qu);
        return res;
    }
};


// 785. Is Graph Bipartite?
class Solution {
public:
    void DFS_check(vector<vector<int>>& graph, vector<int>& color, int vertex, bool& res, int c) {
        color[vertex] = c;
        for (int i=0; i<graph[vertex].size(); i++) {
            int neigh = graph[vertex][i];
            if (color[neigh] != -1 && color[neigh] == c) res = false;
            if (color[neigh] == -1) {
                DFS_check(graph, color, neigh, res, 1-c);
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        bool res = true;
        int c = 0;

        for (int i=0; i<n; i++) {
            if (color[i] == -1){
                DFS_check(graph, color, i, res, c);
            }
        }
        return res;
    }
};


// 130. Surrounded Regions
class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if (i<0 || i>=n || j<0 || j>=m) {
            return false;
        }
        return true;
    }

    void DFS(vector<vector<char>>& board, vector<int>& x_axis, vector<int>& y_axis, int i, int j, int n, int m) {
        board[i][j] = '#';
        for (int k=0; k<4; k++) {
            int row = i + x_axis[k];
            int col = j + y_axis[k];
            if (isValid(row, col, n, m) == true && board[row][col] != '#' && board[row][col] == 'O') {
                DFS(board, x_axis, y_axis, row, col, n, m);
            }
        }
        return;
    }

    void solve(vector<vector<char>>& board) {
        vector<int> x_axis = {1 , -1, 0 , 0};
        vector<int> y_axis = {0 , 0 , 1 , -1};

        int n = board.size();
        int m = board[0].size();

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == 'O') {
                    for (int k=0; k<4; k++) {
                        int row = i + x_axis[k];
                        int col = j + y_axis[k];
                        if (row<0 || row>=n || col<0 || col>=m) {
                            DFS(board, x_axis, y_axis, i, j, n, m);
                        }
                    }
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
        return;
    }
};

// Shortest Path in Unweighted Graph -- GFG.
class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>> adj_list(V);
        
        for (int i=0; i<edges.size(); i++) {
            vector<int> edge = edges[i];
            int source = edge[0];
            int destination = edge[1];
            adj_list[source].push_back(destination);
            adj_list[destination].push_back(source);
        }
        
        vector<bool> visited(V, false);
        vector<int> ans(V,-1);
        int distance = 0;
        
        queue<pair<int,int>> qu;
        qu.push({src,distance});
        visited[src] = true;
        
        while(!qu.empty()) {
            pair<int,int> p = qu.front();
            qu.pop();
            int vertex = p.first;
            int dist = p.second;
            ans[vertex] = dist;
            
            for (int i=0; i<adj_list[vertex].size(); i++) {
                int neigh = adj_list[vertex][i];
                if (visited[neigh] == false) {
                    qu.push({neigh, dist+1});
                    visited[neigh] = true;
                }
            }
        }
        
        int res = 0;
        for (int i=0; i<ans.size(); i++) {
            res = ans[dest];
        }
        return res;
    }
};


// Dijkstra's algorithm -- GFG
class Solution {
  public:
    struct cmp {
        bool operator () (pair<int,int>& a, pair<int,int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second > b.second;
            }
        }
    };
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        // adj_list for weighted graph
        vector<vector<pair<int, int>>> adj_list(V);
        for (int i=0; i<edges.size(); i++) {
            vector<int> wt_edge = edges[i];
            int source = wt_edge[0];
            int destination = wt_edge[1];
            int weight = wt_edge[2];
            
            adj_list[source].push_back({destination,weight});
            adj_list[destination].push_back({source, weight});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; // min_heap.
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;
        pq.push({distance[src], src});
        
        while (!pq.empty()) {
            pair<int,int> p;
            p = pq.top();
            pq.pop();
            int dist = p.first;
            int vertex = p.second;
            
            if (dist > distance[vertex]) continue;
            
            for (int j=0; j<adj_list[vertex].size(); j++) {
                int neigh = adj_list[vertex][j].first;
                int weight = adj_list[vertex][j].second;
                if (dist+weight < distance[neigh]) {
                    distance[neigh] = dist+weight;
                    pq.push({dist+weight,neigh});
                }
            }
        }
        return distance;
    }
};
