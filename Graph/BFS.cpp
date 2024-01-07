#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj_list[MAX_N];
vector<bool> visited(MAX_N);
vector<int> dist(MAX_N);

void BFS(int src) {
    queue<int> Q;
    Q.push(src);
    visited[src] = 1;

    while(!Q.empty()) {
        int elem = Q.front();
        Q.pop();

        for(auto u : adj_list[elem]) {
            if(!visited[u]) {
                dist[u] = dist[elem] + 1;
                visited[u] = 1;
                Q.push(u);
            }
        }

    }
}

int main() {
    int node, edges;
    cin >> node >> edges;

    while(edges--) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    BFS(1);

    for(int i = 1; i <= 9; i++) {
        cout << i << " : " << dist[i] << endl;
    }
    
    return 0;
}