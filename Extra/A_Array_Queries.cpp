#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> arr(N);
int min_tree[4 * N];

void build_tree(int st, int en, int node) {
    if(st == en) {
        min_tree[node] = arr[st];
        return;
    }

    int M = st + (en - st) / 2;

    build_tree(st, M, node + node);
    build_tree(M + 1, en, node + node + 1);

    min_tree[node] = min(min_tree[node + node], min_tree[node + node + 1]);
}

int range_query(int st, int en, int L, int R, int node) {
    if(st >= L && en <= R) {
        return min_tree[node];
    }

    if(st > R || L > en) {
        return INT_MAX / 2;
    }
    int M = st + (en - st) / 2;

    auto left_min = range_query(st, M, L, R, node + node);
    auto right_min = range_query(M + 1, en, L, R, node + node + 1);

    return min(left_min, right_min);
}

int main() {
    int t, cs = 1;
    scanf("%d", &t);

    while(t--) {
        printf("Case %d:\n", cs++);
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        build_tree(0, n - 1, 1);

        while(q--) {
            int L, R;
            scanf("%d %d", &L, &R);

            printf("%d\n", range_query(0, n - 1, L - 1, R - 1, 1));
        }

    }
    return 0;
}