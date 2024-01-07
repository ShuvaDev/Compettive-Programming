#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 2e5 + 10;
vector<vector<int>> adj_list(MAX_N);
vector<bool> visited(MAX_N);
vector<int> path;

bool dfs(int src, int parent) {
    visited[src] = 1;
    path.push_back(src);

    for(auto v : adj_list[src]) 
    if(!visited[v]) {
        if(dfs(v, src) == true) return true;
    }
    else
    if(parent != v) {
        path.push_back(v);
        return true;
    }

    path.pop_back();
    return false;
     
}



int main() {

    int t;
    cin >> t;

    while(t--) {
        adj_list.clear();
        path.clear();
        path.resize(0);

        int n, src, dst;
        cin >> n >> src >> dst;

        for(int i = 0; i <= n; i++) {visited[i] = 0;}
        for(int i = 0; i <= n; i++) {adj_list[i] = {};}

        for(int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        dfs(1, -1);

        int last_item = path.back(), ind = path.size() - 2;
        

        int count = 0;
        
        if(last_item == src || last_item == dst) count++;
        
        while(ind >= 0 && path[ind] != last_item) {
            if(path[ind] == src || path[ind] == dst) count++;
            ind--;
        }
        cout << count;
        cout << endl;


        
        cout << endl;
    }

    
    
    return 0;
}