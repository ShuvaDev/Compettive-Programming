#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 200005;
vector<long long> sum_tree(4 * MAX_N);

long long range_sum(int st, int en, int L, int R, int node) {
    if(st >= L && en <= R) return sum_tree[node];
    if(st > R || en < L) return 0;

    int M = st + (en - st) / 2;
    auto left_cnt = range_sum(st, M, L, R, 2 * node);
    auto right_cnt = range_sum(M + 1, en, L, R, 2 * node + 1);

    return left_cnt + right_cnt;
}

void build_tree(int L, int R, vector<int> &vec, int node) {
    if(L == R) {
        sum_tree[node] = vec[L];
        return;
    }

    int M = L + (R - L) / 2;
    build_tree(L, M, vec, 2 * node);
    build_tree(M + 1, R, vec, 2 * node + 1);

    sum_tree[node] = sum_tree[2 * node] + sum_tree[2 * node + 1];
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    vector<int> vec(n);
    for(int i = 0; i < n; i++) scanf("%d", &vec[i]);
     
    build_tree(0, vec.size() - 1, vec, 1);

    while(q--) {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%lld\n", range_sum(0, n - 1, a - 1, b - 1, 1));
    }

    return 0;
}