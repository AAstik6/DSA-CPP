#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> make_adjList(int n, vector<vector<int>>& edges, vector<vector<int>>& adj_list) {
    for (int i=0; i<edges.size(); i++) {
        vector<int> edge = edges[i];
        int source = edge[0];
        int destination = edge[1];
        adj_list[source].push_back(destination);
        adj_list[destination].push_back(source);
    }
    return adj_list;
}
vector<vector<int>> adjList() {
    int n = 5; // number of vertices
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}}; // number of edges.
    vector<vector<int>> adj_list(n);
    make_adjList(n, edges, adj_list);
    return adj_list;
}
int main() {
    vector<vector<int>> result = adjList();
    for (int i = 0; i < result.size(); i++) {
        cout << i << ": ";
        for (int neighbor : result[i]) cout << neighbor << " ";
        cout << endl;
    }
    return 0;
}
