#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> adj_list[1000];
vector<bool> visited;
vector<bool> color;

bool isBipartite(int src) {
    visited[src] = 1;

    for(auto x : adj_list[src]) {
        if(!visited[x]) {
            color[x] = !color[src];
            return isBipartite(x);
        } else {
            if(color[x] == color[src]) {
                return false;
            } else {
                continue;
            }
        }
    }
    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    visited.resize(n + 1);
    color.resize(n + 1);

    while(e--) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    color[1] = 0;
    
    cout << boolalpha << isBipartite(1);
    
    return 0;
}