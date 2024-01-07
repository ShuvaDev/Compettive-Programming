#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N =  100005;
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

int main() {
    int t, cs = 1;
    cin >> t;

    while(t--) {
        cout << "Case " << cs++ << ":\n";
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        build_tree(0, n - 1, 1);

        while(q--) {
            int L, R;
            scanf("%d %d", &L, &R);

            printf("%d\n", range_query(0, n - 1, L - 1, R - 1, 1));

        }
    }
    
    
    
    return 0;
}