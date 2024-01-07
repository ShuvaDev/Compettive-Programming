#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;


class Node {
    public:
        long long sum, pSum, sSum, best;

        Node() {}

        Node(int val) {
            sum = pSum = sSum = best = val;
        }

        Node(int a, int b, int c, int d) {
            sum = a, pSum = b, sSum = c, best = d;
        }

        void merge_them(Node &left, Node &right) {
            pSum = max(left.pSum, left.sum + right.pSum);
            sSum = max(right.sSum, left.sSum + right.sum);
            sum = left.sum + right.sum;
            best = max({left.best, right.best, left.sSum + right.pSum});
        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
};
const int MAX_N = 50000 + 10;
array<int, MAX_N> arr;
Node tree[4 * MAX_N];

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = Node(arr[st]);
        return;
    }

    int M = st + (en - st) / 2;
    
    build_tree(st, M, node + node);
    build_tree(M + 1, en, node + node + 1);

    Node result;
    result.merge_them(tree[2 * node], tree[2 * node + 1]);
    tree[node] = result;
}

Node range_sum(int st, int en, int L, int  R, int node) {
    if(st >= L && en <= R) {
        return tree[node];
    } 
    if(st > R || en < L) {
        return Node(0, INT_MIN / 2, INT_MIN / 2, INT_MIN / 2);
    }
    int M = st + (en - st) / 2;
    auto left_cnt = range_sum(st, M, L, R, node + node);
    auto right_cnt = range_sum(M + 1, en, L, R, node + node + 1);

    Node result;
    result.merge_them(left_cnt, right_cnt);
    return result;
}


int main() {
    int n, q;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    build_tree(0, n - 1, 1);

    scanf("%d", &q);
    while(q--) {
        int L, R;
        scanf("%d %d", &L, &R);
        printf("%lld\n", range_sum(0, n - 1, L - 1, R - 1, 1).best);
    }
    
    
    
    return 0;
}