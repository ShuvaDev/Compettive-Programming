#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 10000 + 5;
vector<int> adj_list[MAX_N];
vector<int> visited(MAX_N);

void DFS(int src) {
    visited[src] = 1;

    for(auto v : adj_list[src]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for(int i = 1; i <= e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    if(n == (e + 1)) {
        int conected_comp = 0;
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                conected_comp++;
                DFS(i);
            }
        }
        // cout << conected_comp;
        if(conected_comp == 1) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
    
    
    return 0;
}