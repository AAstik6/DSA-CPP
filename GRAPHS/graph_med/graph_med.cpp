#include<iostream>
#include<vector>
using namespace std;


// 200. Number of Islands
class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if (row<0 || row>=n || col<0 || col>=m) return false;
        return true;
    }

    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<int>& x_axis, vector<int>& y_axis, int i, int j, int n, int m) {

        visited[i][j] = true;

        for (int k=0; k<4; k++) {
            int row = i + x_axis[k];
            int col = j + y_axis[k];
            if (isValid(row, col, n, m) == true && visited[row][col] == false && grid[row][col] == '1') {
                DFS(grid, visited, x_axis, y_axis, row, col, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int num_islands = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<int> x_axis = {1, -1, 0, 0};
        vector<int> y_axis = {0, 0, 1, -1};

        for (int i=0; i<n; i++) {
            for( int j=0; j<m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    DFS(grid, visited, x_axis, y_axis, i, j, n, m);
                    num_islands++;
                }
            }
        }

        return num_islands;
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

            // making the adj_list
            vector<vector<pair<int,int>>> adj_list(V);
            for (int i=0; i<edges.size(); i++) {
                vector<int> edge = edges[i];
                int source = edge[0];
                int destination = edge[1];
                int weight = edge[2];

                adj_list[source].push_back({destination, weight});
                adj_list[destination].push_back({source, weight});
            }
            vector<int> distance(V,INT_MAX);
            distance[src] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; // min_heap.
            pq.push({distance[src], src});

            while (!pq.empty()) {
                pair<int,int> p;
                p = pq.top();
                pq.pop();

                int dist = p.first;
                int vertex = p.second;

                if (distance[vertex] < dist) continue;

                for (int j=0; j<adj_list[vertex].size(); j++) {
                    int neigh = adj_list[vertex][j].first;
                    int weight = adj_list[vertex][j].second;
                    if (dist + weight < distance[neigh]) {
                        distance[neigh] = dist+weight;
                        pq.push({dist+weight, neigh});
                    }
                }
            }
            return distance;
        }
    };

// Network Delay Time -- LeetCode,743
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency List
        vector<vector<pair<int,int>>> adj_list;
        adj_list.resize(n+1);
        for (int i=0; i<times.size(); i++) {
            vector<int> edge = times[i];
            int src = edge[0];
            int dest = edge[1];
            int wt = edge[2];

            adj_list[src].push_back({dest,wt});
        }

        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; // min_heap.
        pq.push({distance[k], k});

        while (!pq.empty()) {
            pair<int,int> p;
            p = pq.top();
            pq.pop();
            int dist = p.first;
            int vertex = p.second;
            if (distance[vertex] < dist) continue;
            for(int i=0; i<adj_list[vertex].size(); i++) {
                int neigh = adj_list[vertex][i].first;
                int wt = adj_list[vertex][i].second;
                if (dist + wt < distance[neigh]) {
                    distance[neigh] = dist + wt;
                    pq.push({dist+wt, neigh});
                }
            }
        }

        int min_time = 0;
        for(int i=1; i<distance.size(); i++) {
            if (distance[i] == INT_MAX) return -1;
            min_time = max(min_time, distance[i]);
        }
        return min_time;
    }
};


// Minimum Effort Path -- LeetCode, 1631
class Solution {
public:

    struct cmp {
        bool operator() (pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second > b.second;
            }
        }
    };

    bool isValid(int row, int col, int& n, int& m) {
        if (row>=n || row<0 || col<0 || col>=m) return false;
        return true;
    }

    void DijkSearch(vector<vector<int>>& heights, vector<vector<int>>& dist_check, vector<int>& x_axis, vector<int>& y_axis, int& n, int& m, int& src) {

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq; // min_heap.
        pq.push({dist_check[0][0], {0,0}});

        while (!pq.empty()) {
            pair<int, pair<int,int>> p;
            p = pq.top();
            pq.pop();
            int dist = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if (dist > dist_check[row][col]) continue;

            for (int i=0; i<4; i++) {
                int r = row + x_axis[i];
                int c = col + y_axis[i];
                if (isValid(r, c, n, m) == true) {
                    int neigh = heights[r][c];
                    int diff = abs(heights[row][col] - neigh);
                    int effort = max(dist,diff);
                    if (effort < dist_check[r][c]) {
                        dist_check[r][c] = effort;
                        pq.push({effort, {r,c}});
                    }
                }
            }
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        vector<int> x_axis = {1 , -1 , 0, 0};
        vector<int> y_axis = {0 , 0 , 1 , -1};

        int n = heights.size();
        int m = heights[0].size();
        int src = heights[0][0];

        vector<vector<int>> dist_check(n);
        for (int i=0; i<n; i++) {
            vector<int> t(m, INT_MAX);
            dist_check[i] = t;
        }
        dist_check[0][0] = 0;

        DijkSearch(heights, dist_check, x_axis, y_axis, n, m, src);

        int min_effort = dist_check[n-1][m-1];
        return min_effort;
    }
};

// Bellman Ford -- GFG.
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> res(V, 1e8);
        res[src] = 0;

        for (int i=0; i<V-1; i++) { // i<n-1 as we need to relax the vertices for n-1 times only.
            for (int j=0; j<edges.size(); j++) {
                vector<int> edge = edges[j];
                int source = edge[0];
                int destination = edge[1];
                int weight = edge[2];
                if (res[source] != 1e8 && res[source]+weight < res[destination])  {
                    res[destination] = res[source] + weight;
                }
            }
        }

        for (int k=0; k<edges.size(); k++) {
            vector<int> edge = edges[k];
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];
            if (res[source] != 1e8 && res[source]+weight < res[destination]) return {-1}; // detects cycle for -ve weighted graph.
        }
        return res;
    }
};

// 3286. Find a Safe Walk Through a Grid
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b) const {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second > b.second;
            }
        }
    };

    bool isValid(int row, int col, int n, int m) {
        if (row<0 || row>=n || col<0 || col>=m) return false;
        return true;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int src = grid[0][0];
        int destination = grid[n-1][m-1];

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        distance[0][0] = grid[0][0];

        vector<int> x_axis = {1 , -1 , 0 , 0};
        vector<int> y_axis = {0 , 0 , 1 , -1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq;
        pq.push({distance[0][0], {0,0}});

        while (!pq.empty()) {
            pair<int,pair<int,int>> p;
            p = pq.top();
            pq.pop();
            int row = p.second.first;
            int col = p.second.second;
            int weight = p.first;

            if (weight > distance[row][col]) continue;

            for (int k=0; k<4; k++) {
                int r = row + x_axis[k];
                int c = col + y_axis[k];
                if (isValid(r, c, n, m) == true && distance[r][c] > grid[r][c] + weight) {
                    distance[r][c] = grid[r][c] + weight;
                    pq.push({distance[r][c], {r,c}});
                }
            }
        }
        if (health - distance[n-1][m-1] > 0) return true;
        return false;
    }
};

// 3341. Find Minimum Time to Reach Last Room I
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b) const {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second > b.second;
            }
        }
    };

    bool isValid(int row, int col, int n, int m) {
        if (row<0 || row>=n || col<0 || col>=m) return false;
        return true;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> time_track(n, vector<int>(m, INT_MAX));
        time_track[0][0] = 0;

        vector<int> x_axis = {1 , -1 , 0 , 0};
        vector<int> y_axis = {0 , 0 , 1 , -1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq;
        pq.push({0, {0,0}});

        while (!pq.empty()) {
            pair<int,pair<int,int>> p;
            p = pq.top();
            pq.pop();
            int row = p.second.first;
            int col = p.second.second;
            int weight = p.first;

            if (time_track[row][col] > weight) continue;


            for (int k=0; k<4; k++) {
                int r = row + x_axis[k];
                int c = col + y_axis[k];

                if (isValid(r,c,n,m) == true) {
                    int newTime = max(weight , moveTime[r][c]) + 1;
                    if (time_track[r][c] > newTime) {
                        time_track[r][c] = newTime;
                        pq.push({time_track[r][c],{r,c}});
                    }
                }
            }
        }
        int min_time = time_track[n-1][m-1];
        return min_time;
    }
};
