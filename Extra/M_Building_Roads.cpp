#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 100005;
vector<int> adj_list[MAX_N];
vector<int> visited(MAX_N);

void DFS(int src) {
    visited[src] = 1;

    for(auto u : adj_list[src]) {
        if(!visited[u]) {
            DFS(u);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);


    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    int cnt = 0;
    vector<int> roads;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            roads.push_back(i);
            cnt++;
            DFS(i);
        }
    }

    printf("%d\n", cnt - 1);
    for(int i = 0; i < roads.size() - 1; i++) {
        printf("%d %d\n", roads[i], roads[i + 1]);
    }
    
    return 0;
}