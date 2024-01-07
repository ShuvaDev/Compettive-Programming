// https://www.spoj.com/problems/GSS1/
#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 50000 + 5;

class Node {
    public:
        long long pSum, sSum, sum, best;
        Node() {}
        Node(int val) {
            pSum = val, sSum = val, sum = val, best = val;
        }
        Node(int a, int b, int c, int d) {
            pSum = a, sSum = b, sum = c, best = d;
        } 
        void merge_them(Node &left, Node &right) {
            pSum = max(left.pSum, left.sum + right.pSum);
            sSum = max(right.sSum, left.sSum + right.sum);
            sum = left.sum + right.sum;
            best = max({left.best, right.best, left.sSum + right.pSum});
        }
};

Node tree[MAX_N * 4];
array<int, MAX_N> arr;

void build_tree(int st, int en, int node) {
    if(st == en) {
        tree[node] = Node(arr[st]);
        return;
    }

    int M = st + (en - st) / 2;
    build_tree(st, M, 2 * node);
    build_tree(M + 1, en, 2 * node + 1);

    tree[node].merge_them(tree[2 * node], tree[2 * node + 1]);
}

Node range_query(int st, int en, int L, int R, int node) {
    if(st >= L && en <= R) return tree[node];
    if(st > R || en < L) return Node(INT_MIN / 2, INT_MIN / 2, 0, INT_MIN / 2);

    int M = st + (en - st) / 2;
    auto left_cnt = range_query(st, M, L, R, 2 * node);
    auto right_cnt = range_query(M + 1, en, L, R, 2 * node + 1);

    Node result;
    result.merge_them(left_cnt, right_cnt);
    return result;
}

int main() {
    int n, m;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    build_tree(0, n - 1, 1);
    scanf("%d", &m);

    while(m--) {
        int L, R;
        scanf("%d %d", &L, &R);

        

        printf("%lld\n", range_query(0, n - 1, L - 1, R - 1, 1).best);
    }
    return 0;
}

