// https://lightoj.com/problem/curious-robin-hood

#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
array<int, MAX_N> arr;
vector<long long> tree(4 * MAX_N);

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = arr[st];
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, node + node);
    build_tree(M + 1, en, node + node + 1);

    tree[node] = tree[node + node] + tree[node + node + 1];
}

void update_money(int st, int en, int ind, int val, int node) {
    if(st == en && st == ind) {
        tree[node] = tree[node] + val;
        return;
    }

    if(st > ind || ind > en) {
        return;
    }

    int M = st + (en - st) / 2;
    update_money(st, M, ind, val, node + node);
    update_money(M + 1, en, ind, val, node + node + 1);

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

            int type;
            scanf("%d", &type);

            if(type == 1) {
                int i;
                scanf("%d", &i);
                long long sum = range_sum(0, n - 1, i, i, 1);
                printf("%lld\n", sum);
                
                update_money(0, n - 1, i, 0 - sum, 1);
            } else if(type == 2) {
                int i, v;
                scanf("%d %d", &i, &v);

                update_money(0, n - 1, i, v, 1);
            } else {
                int i, j;
                scanf("%d %d", &i, &j);

                printf("%lld\n", range_sum(0, n - 1, i, j, 1));
            }
        }
    }
    
    
    
    return 0;
}