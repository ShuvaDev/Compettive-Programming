#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
int nval[MAX_N + 5];
bool visited[MAX_N + 5];
vector<int> adj_list[MAX_N + 5];
vector<pair<int, int>> startEndTime(MAX_N + 5);
vector<int> arr(2 * MAX_N);
vector<long long> tree(MAX_N * 8);

int T = 0;

void dfs(int src) {
    startEndTime[src].first = ++T;
    visited[src] = 1;

    for(auto v : adj_list[src]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
    startEndTime[src].second = ++T;
}

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = arr[st];
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, node + node);
    build_tree(M + 1, en , node + node + 1);

    tree[node] = tree[node + node] + tree[node + node + 1];
}

long long range_sum(int st, int en, int L, int R, int node) {
    if(st >= L && en <= R) return tree[node];
    if(st > R || en < L) return 0;

    int M = st + (en - st) / 2;
    auto left_cnt = range_sum(st, M, L, R, 2 * node);
    auto right_cnt = range_sum(M + 1, en, L, R, 2 * node + 1);

    return left_cnt + right_cnt;
}

void point_update(int st, int en, int ind, int x, int node) { 
    if(ind < st || en < ind) return;
    if(st == en && st == ind) {
        tree[node] = x;
        return;
    }

    int M = st + (en - st) / 2;

    point_update(st, M, ind, x, 2 * node);
    point_update(M + 1, en, ind, x, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    // Input the value of node
    for(int i = 1; i <= n; i++) {
        scanf("%d", &nval[i]);
    }

    // Taking input graph
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    dfs(1);
    
    for(int i = 1; i <= n; i++) {
        arr[startEndTime[i].first] = nval[i];
    }
    
    build_tree(1, T, 1);

    while(q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int s, x;
            scanf("%d %d", &s, &x);
            int ind = startEndTime[s].first;
            point_update(1, T, ind, x, 1);
        } else {
            int s;
            scanf("%d", &s);
            cout << range_sum(1, T, startEndTime[s].first, startEndTime[s].second, 1) << endl;
        }
    }
    
    
    
    return 0;
}