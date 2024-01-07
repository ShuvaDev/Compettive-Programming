#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

vector<int> vc;
vector<int> parent;

int findParent(int u) {
    if(parent[u] == u) return u;

    return parent[u] = findParent(parent[u]);
}

void join(int u, int v) {
    auto pu = findParent(u);
    auto pv = findParent(v);

    if(pu != pv) {

        parent[pu] = pv;
        vc[pv] += vc[pu];
    }
}

int main() {
    int t, cs = 1;
    cin >> t;

    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        vc.clear();
        parent.clear();

        vc.resize(n + 1);
        parent.resize(n + 1);

        iota(parent.begin(), parent.end(), 0);

        for(int i = 1; i <= n; i++) {
            scanf("%d", &vc[i]);
        } 

        while(m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            join(u, v);
        }

        vector<int> result;
        vector<bool> vis(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            
            auto parent = findParent(i);
            if(!vis[parent]) {
                vis[parent] = 1;
                if(parent == i) {
                    result.push_back(vc[i]);
                } else {
                    result.push_back(vc[parent]);
                }
            }

        }
        sort(result.begin(), result.end());
        cout << "Case " << cs++ << ": " << result.size() << endl;
        for(auto r : result) cout << r << " ";
        cout << endl;


    }
    
    
    
    return 0;
}