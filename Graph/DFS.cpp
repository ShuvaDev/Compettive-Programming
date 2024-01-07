#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> adj[MAX_N];
vector<bool> vis(MAX_N);
vector<int> dist(MAX_N);

void DFS(int src) {
    // cout << src << endl;
    vis[src] = 1;

    for(auto v : adj[src]) {
        if(!vis[v]) {
            dist[v] = dist[src] + 1;
            DFS(v);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while(e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    DFS(1);
    
    for(int i = 1; i <= 7; i++) {
        cout << "Node : " << i << " Distance : " << dist[i] << endl;
    }
    
    return 0;
}