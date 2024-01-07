#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> adj_list[MAX_N];
vector<bool> vis(MAX_N);

void DFS(int src) {
    vis[src] = 1;
    for(auto v : adj_list[src]) {
        if(!vis[v]) {
            DFS(v);
        }
    }
}

int numberOfConnectedComp(int total_node) {
    int count = 0;
    for(int i = 1; i <= total_node; i++) {
        if(!vis[i]) {
            count++;
            DFS(i);
        }
     }
    return count;
}

int main() {
    int node, edge;
    scanf("%d %d", &node, &edge);


    while(edge--) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    cout << numberOfConnectedComp(node);
    
    
    return 0;
}