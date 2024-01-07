#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 100005;
array<int, MAX_N> arr;
vector<int> tree[4 * MAX_N];

// merge sort tree
void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node].push_back(arr[st]);
        return;
    }
    int M = st + (en - st) / 2;
    build_tree(st, M, 2 * node);
    build_tree(M + 1, en, 2 * node + 1);

    tree[node].resize(en - st + 1);

    merge(tree[2 * node].begin(), tree[2 * node].end(), 
    tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
    tree[node].begin());
}

int less_or_equal_than(int st, int en, int L, int R, int node, int x) {
    if(R < st || en < L) return 0;
    if(st >= L && en <= R) return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();

    int M = st + (en - st) / 2;
    auto left_count = less_or_equal_than(st, M, L, R, 2 * node, x);
    auto right_count = less_or_equal_than(M + 1, en, L, R, 2 * node + 1, x);

    return left_count + right_count;
}

int solve(int L, int R, int k, int n) {
    int lo = INT_MIN / 2;
    int hi = INT_MAX / 2;

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(less_or_equal_than(0, n - 1, L, R, 1, mid) < k) {
            lo = mid + 1;
        } else if(less_or_equal_than(0, n - 1, L, R, 1, mid) > k) {
            hi = mid - 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build_tree(0, n-1, 1);

    while(q--) {
        int L, R, k;
        cin >> L >> R >> k;

        cout << solve(L - 1, R - 1, k, n) << endl;

    }
    
    return 0;
}