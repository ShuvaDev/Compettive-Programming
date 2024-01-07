// https://cses.fi/problemset/task/1669/

#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj_list[MAX_N];
vector<bool> vis(MAX_N);
vector<int> path;

bool dfs(int src, int parent) {
    vis[src] = 1;
    path.push_back(src);

    for(auto v : adj_list[src]) {
        if(!vis[v]) {
            if(dfs(v, src) == true) return true;
        } else {
            if(parent != v) {
                path.push_back(v);
                return true;
            }
        }
    }
    path.pop_back();
    return false;
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
    
    int flag = 0;
    for(int i = 1; i <= n; i++) {
        path.clear();
        path.resize(0);

        if(!vis[i]) {
            if(dfs(i, -1)) {
                flag = 1;
                break;
            }

        }
    }

    if(flag) {
        int last_node = path.back(), ind = path.size() - 2;
        vector<int> result;
        result.push_back(last_node);
        while(path[ind] != last_node && ind >= 0) {
            result.push_back(path[ind]);
            ind--;
        }
        result.push_back(last_node);
        cout << result.size() << endl;
        for(auto p : result) {
            cout << p << " ";
        }
    } else {
        cout << "There are no cycle";
    }
    
    
    return 0;
}