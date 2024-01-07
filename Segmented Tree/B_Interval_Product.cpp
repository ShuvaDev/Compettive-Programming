#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
array<int, MAX_N> arr;
vector<int> tree(4 * MAX_N);

void build_tree(int st, int en, int node) {
    if(st == en) {
        if(arr[st] == 0) {
            tree[node] = 0;
        } else if(arr[st] < 0) {
            tree[node] = -1;
        } else {
            tree[node] = 1;
        }
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, 2 * node);
    build_tree(M + 1, en, 2 * node + 1);

    tree[node] = tree[2 * node] * tree[2 * node + 1];
}

void update_query(int st, int en, int ind, int val, int node) {
    if(st == en && st == ind) {
        if(val == 0) {
            tree[node] = 0;
        } else if(val < 0) {
            tree[node] = -1;
        } else {
            tree[node] = 1;
        }
        return;
    }
    if(ind < st || ind > en) return;

    int M = st + (en - st) / 2;
    update_query(st, M, ind, val, node + node);
    update_query(M + 1, en, ind, val, node + node + 1);

    tree[node] = tree[2 * node] * tree[2 * node + 1];
}

int product_query(int st, int en, int L, int R, int node) {
    if(st >= L && en <= R) {
        return tree[node];
    }
    if(st > R || en < L) {
        return 1;
    }

    int M = st + (en - st) / 2;
    auto left_p = product_query(st, M, L, R, 2 * node);
    auto right_p = product_query(M + 1, en, L, R, 2 * node + 1);

    return left_p * right_p;
}

int main() {
    int n, q;

    while(cin >> n >> q) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }      

        build_tree(0, n - 1, 1);

        while(q--) {
            char type;
            int i, j;
            cin >> type >> i >> j;

            if(type == 'C') {
                update_query(0, n - 1, i - 1, j, 1);
            } else {
                int result = product_query(0, n - 1, i - 1, j - 1, 1);
                if(result == 0) {
                    cout << "0";
                } else if(result == -1) {
                    cout << "-";
                } else {
                    cout << "+";
                }
            }

        }
        cout << endl;

    }

    
    
    
    
    return 0;
}