#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 4;

class Node {
    public:
        long long mod3Equal0, mod3Equal1, mod3Equal2, propagation;

        Node() {}
        Node(long long m3e0, long long m3e1, long long m3e2, long long p) {
            propagation += p;
            mod3Equal0 = m3e0;
            mod3Equal1 = m3e1;
            mod3Equal2 = m3e2;
        }
};

Node tree[4 * MAX_N];

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = Node(1, 0, 0, 0);
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, 2 * node);
    build_tree(M + 1, en, 2 * node + 1);

    tree[node].mod3Equal0 = tree[2 * node].mod3Equal0 + tree[2 * node + 1].mod3Equal0;
    tree[node].mod3Equal1 = tree[2 * node].mod3Equal1 + tree[2 * node + 1].mod3Equal1;
    tree[node].mod3Equal2 = tree[2 * node].mod3Equal2 + tree[2 * node + 1].mod3Equal2;
    tree[node].propagation = 0;
}

void range_update(int st, int en, int L, int R, int val, int node) {
    if(st > R || L > en) {
        return;
    }
    if(st >= L && en <= R) {
        tree[node].propagation += val;
        
        auto temp = tree[node].mod3Equal1;
        tree[node].mod3Equal1 = tree[node].mod3Equal0;
        tree[node].mod3Equal0 = tree[node].mod3Equal2;
        tree[node].mod3Equal2 = temp;

        return;
    }

    int M = st + (en - st) / 2;
    range_update(st, M, L, R, val, 2 * node);
    range_update(M + 1, en, L, R, val, 2 * node + 1);

    tree[node].mod3Equal0 = tree[2 * node].mod3Equal0 + tree[2 * node + 1].mod3Equal0;
    tree[node].mod3Equal1 = tree[2 * node].mod3Equal1 + tree[2 * node + 1].mod3Equal1;
    tree[node].mod3Equal2 = tree[2 * node].mod3Equal2 + tree[2 * node + 1].mod3Equal2;

    if(tree[node].propagation % 3 == 2) {
        auto temp = tree[node].mod3Equal0;
        tree[node].mod3Equal0 = tree[node].mod3Equal1;
        tree[node].mod3Equal1 = tree[node].mod3Equal2;
        tree[node].mod3Equal2 = temp;
    } else if(tree[node].propagation % 3 == 1) {
        auto temp = tree[node].mod3Equal1;
        tree[node].mod3Equal1 = tree[node].mod3Equal0;
        tree[node].mod3Equal0 = tree[node].mod3Equal2;
        tree[node].mod3Equal2 = temp;
    }
}

long long range_query(int st, int en, int L, int R, int node, long long carry = 0) {
    if(st > R || L > en) {
        return 0;
    }
    if(st >= L && en <= R) {
        if(carry % 3 == 2) {
            return tree[node].mod3Equal1;
        } else if(carry % 3 == 1) {
            return tree[node].mod3Equal2;
        }
        return tree[node].mod3Equal0;
    }

    int M = st + (en - st) / 2;
    auto left_sum = range_query(st, M, L, R, 2 * node, carry + tree[node].propagation);
    auto right_sum = range_query(M + 1, en, L, R, 2 * node + 1, carry + tree[node].propagation);

    return left_sum + right_sum;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    build_tree(0, n - 1, 1);


    while(q--) {
        int type, l, r;
        scanf("%d %d %d", &type, &l, &r);

        if(type == 0) {
            range_update(0, n - 1, l, r, 1, 1);
            
        } else {
            printf("%lld\n", range_query(0, n - 1, l, r, 1));
        }
    }
        
    
    
    return 0;
}