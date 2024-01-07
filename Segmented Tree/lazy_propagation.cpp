#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 4;

class Node {
    public:
        long long sum, propagation;

        Node() {}
        Node(int s, int p) {
            sum = s, propagation += p;
        }
};

Node tree[4 * MAX_N];
array<int, MAX_N> arr;

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = Node(arr[st], 0);
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, 2 * node);
    build_tree(M + 1, en, 2 * node + 1);

    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}

void range_update(int st, int en, int L, int R, int val, int node) {
    if(st > R || L > en) {
        return;
    }
    if(st >= L && en <= R) {
        tree[node].propagation += val;
        tree[node].sum += (en - st + 1) * val;
        return;
    }

    int M = st + (en - st) / 2;
    range_update(st, M, L, R, val, 2 * node);
    range_update(M + 1, en, L, R, val, 2 * node + 1);

    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum + (en - st + 1) * tree[node].propagation;
}

int range_sum(int st, int en, int L, int R, int node, int carry = 0) {
    if(st > R || L > en) {
        return 0;
    }
    if(st >= L && en <= R) {
        return tree[node].sum + (carry * (en - st + 1));
    }

    int M = st + (en - st) / 2;
    auto left_sum = range_sum(st, M, L, R, 2 * node, carry + tree[node].propagation);
    auto right_sum = range_sum(M + 1, en, L, R, 2 * node + 1, carry + tree[node].propagation);

    return left_sum + right_sum;
}

int main() {
    arr = {-4, 7, 2, 6, 5, 8, 1, 3};
    int n = arr.size();

    build_tree(0, n - 1, 1);

    range_update(0, n - 1, 0, 7, 2, 1);
    range_update(0, n - 1, 0, 3, 3, 1);

    cout << range_sum(0, n - 1, 5, 7, 1);
    
    return 0;
}