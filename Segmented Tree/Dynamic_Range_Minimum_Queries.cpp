#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 2 * 100005;
vector<int> arr(MAX_N);
vector<int> tree(4 * MAX_N);

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = arr[st];
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, 2 * node);
    build_tree(M + 1, en, 2 * node + 1);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int range_query(int st, int en, int L, int R, int node) {
    if(st >= L && en <= R) return tree[node];
    if(R < st || en < L) return 2 * 1e9;

    int M = st + (en - st) / 2;

    auto left_min = range_query(st, M, L, R, 2 * node);
    auto right_min = range_query(M + 1, en, L, R, 2 * node + 1);

    return min(left_min, right_min);
}

void update_query(int st, int en, int node, int ind, int val) {
    if(st == en && st == ind) {
        tree[node] = val;
        return;
    }
    if(ind < st || ind > en)  return;

    int M = st + (en - st) / 2;
    update_query(st, M, 2 * node, ind, val);
    update_query(M + 1, en, 2 * node + 1, ind, val);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    build_tree(0, n - 1, 1);

    while(q--) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        if(type == 1) {
            update_query(0, n - 1, 1, x - 1, y);
        } else {
            printf("%d\n", range_query(0, n - 1, x - 1, y - 1, 1));
        }

    }
    
    
    
    return 0;
}