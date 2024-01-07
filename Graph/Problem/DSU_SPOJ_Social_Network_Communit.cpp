// https://www.spoj.com/problems/SOCNETC/en/ (DSU)
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> comsize;

int findParent(int x) {
    if(parent[x] == x) 
        return x;

    return parent[x]  = findParent(parent[x]);
}

void join(int s1, int s2, int m) {
    auto ps1 = findParent(s1);
    auto ps2 = findParent(s2);

    if(comsize[ps2] + comsize[ps1] <= m && ps1 != ps2) {
        parent[ps1] = ps2;
        comsize[ps2] += comsize[ps1];
    }
}

bool isSame(int s1, int s2) {
    auto ps1 = findParent(s1);
    auto ps2 = findParent(s2);

    return ps1 == ps2;
}

int printSize(int x) {
    auto px = findParent(x);
    return comsize[px];
}

int main() {
    int n, m, q;
    cin >> n >> m;

    parent.resize(n + 1);
    comsize.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);


    cin >> q;
    while(q--) {
        char type;
        cin >> type;

        int x, y;

        if(type == 'A') {
            cin >> x >> y;
            join(x, y, m);
        } else if(type == 'E') {
            cin >> x >> y;
            if(isSame(x, y)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cin >> x;
            cout << printSize(x) << "\n";
        }
    }
    
    
    
    return 0;
}