#include<bits/stdc++.h>
using namespace std;

int T = 1;

vector<int> arr;
vector<int> adj_list[100], vis(100);
vector<pair<int, int>> startAndEnd(100);

// DFS with start and end time
void dfs(int src) {
    vis[src] = 1;
    startAndEnd[src].first = T++;

    for(auto v : adj_list[src]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    startAndEnd[src].second = T++;
}

void flatTreeToArray(int n) {
    arr.resize(T + 1);
    for(int i = 1; i <= n; i++) {
        arr[startAndEnd[i].first] = i;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while(e--) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1);
    flatTreeToArray(n);
    
    // for(int i = 1; i <= n; i++) {
    //     cout << "Node " << i << "  :  " << startAndEnd[i].first << ", " << startAndEnd[i].second << endl;
    // }

    for(auto v : arr) {
        cout << v << " ";
    }
    return 0;
}