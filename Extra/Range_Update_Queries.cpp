#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 200005;
array<int, MAX_N> arr;

class Node {
    public:
        long long val, prop;
        Node() {}
        Node(int v, int p) {
            val = v, prop = p;
        }
};

Node tree[4 * MAX_N];

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = Node(arr[st], 0);
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, 2 * node);
    build_tree(M + 1, en, 2 * node + 1);
}

void update_query(int st, int en, int L, int R, int val, int node) {
    if(st >= L && en <= R) {
        if(st == en) {
            tree[node].val += val;
        }
        tree[node].prop += val;
        return;
    }
    if(st > R || en < L) return;

    int M = st + (en - st) / 2;
    update_query(st, M, L, R, val, 2 * node);
    update_query(M + 1, en, L, R, val, 2 * node + 1);
}

long long find_val(int st, int en, int ind, int node, long long carry = 0) {
    if(st == en && st == ind) {
        return tree[node].val + carry;
    }

    int M = st + (en - st) / 2;

    if(ind >= st && ind <= M) {
        return find_val(st, M, ind, 2 * node, carry + tree[node].prop);
    } else {
        return find_val(M + 1, en, ind, 2 * node + 1, carry + tree[node].prop);
    }
}

int main() {
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
            int l, r, v;
            scanf("%d %d %d", &l, &r, &v);
            update_query(0, n - 1, l - 1, r - 1, v, 1);
        } else {
            int k;
            scanf("%d", &k);
            printf("%lld\n", find_val(0, n - 1, k - 1, 1));
        }
    }
    
    return 0;
}