#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int findParent(int u) {
    if(u == parent[u]) return u;

    return parent[u] = findParent(parent[u]);
}

bool isSame(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    return pu == pv;
}

void join(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    parent[pu] = pv;
}

int main() {
    int node;
    cin >> node;
    parent.clear();

    parent.resize(node);

    // nijeke nijer parent hisebe set kora i.e. 0 er captain 0, 1 er 1 ...
    iota(parent.begin(), parent.end(), 0);

    join(1, 2);
    join(1, 3);

    cout << isSame(1, 3);
    
    
    
    return 0;
}