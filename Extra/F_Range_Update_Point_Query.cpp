#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2 * 1e5 + 5;
vector<int> arr(MAX_N);


class Node {
    public:
        int val, prop;

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

    tree[node].prop = 0;
}

int sumOfDigit(int n) {
    int sum = 0;
    while(n) {
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

void update_query(int st, int en, int l, int r, int node) {
    if(r < st || en < l) {
        return;
    }
    if(st >= l && en <= r) {
        tree[node].prop += 1;

        if(st == en) {
            // if tree[node].val / 10 == 0 then not need to call sumOfDigit
            if(tree[node].val / 10 > 0) {
                tree[node].val = sumOfDigit(tree[node].val);
            }
        }
        return;
    }

    int M = st + (en - st) / 2;
    update_query(st, M, l, r, 2 * node);
    update_query(M + 1, en, l, r, 2 * node + 1);
}

int find_val(int st, int en, int ind, int node, int carry = 0) {
    if(st == en && st == ind) {
        int sum = tree[node].val;
        // Highest 2 times need to call sumOfDigit
        for(int i = 1; i <= carry; i++) {
            if(sum / 10 == 0) {
                break;
            }
            sum = sumOfDigit(sum);
        }
        return sum;
    }

    int M = st + (en - st) / 2;
    if(ind >= st && ind <= M) {
        return find_val(st, M, ind, 2 * node, carry + tree[node].prop);
    } else {
        return find_val(M + 1, en, ind, 2 * node + 1, carry + tree[node].prop);
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        build_tree(0, n -1, 1);

        while(q--) {
            int type;
            scanf("%d", &type);

            if(type == 1) {
                int l, r;
                scanf("%d %d", &l, &r);

                update_query(0, n - 1, l -1, r - 1, 1);

            } else {
                int ind;
                scanf("%d", &ind);

                printf("%d\n", find_val(0, n - 1, ind - 1, 1));
            }
        }
    }
    
    
    
    return 0;
}