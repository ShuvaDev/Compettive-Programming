#include<bits/stdc++.h>
using namespace std;

int n;
const int MAX_N = 2e5 + 5; 
vector<int> arr(MAX_N);
int tree[4 * MAX_N];

void update(int st, int en, int node, int indx, int val) {
    if(st == en && st == indx) {
        tree[node] = val;
        return;
    }
    if(indx < st || en < indx) {
        return;
    }

    int M = st + (en - st) / 2;

    update(st, M, node + node, indx, val);
    update(M + 1, en, node + node + 1, indx, val);

    tree[node] = max(tree[node + node], tree[node + node + 1]);
}

int query(int st, int en, int node, int l, int r) {
    if(l <= st && en <= r) {
        return tree[node];
    }
    if(r < st || en < l) {
        return 0;
    }
    int M = st + (en - st) / 2;
    auto left_max = query(st, M, node + node, l, r);
    auto right_max = query(M + 1, en, node + node + 1, l, r);

    return max(left_max, right_max); 
}


void compress_array() {
    vector<pair<int, int>> varr(n);

    for(int i = 0; i < n; i++) {
        varr[i] = {arr[i], i};
    }
    sort(varr.begin(), varr.end());

    int it = 1;
    unordered_map<int, int> valmap;

    for(int i = 0; i < n; i++) {
        if(valmap.count(varr[i].first) == 0) {
            valmap[varr[i].first] = it++;
            varr[i].first = valmap[varr[i].first];
        } else {
            varr[i].first = valmap[varr[i].first];
        }
    }

    sort(varr.begin(), varr.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    });

    for(int i = 0; i < n; i++) {
        arr[i] = varr[i].first;
    }
     
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    compress_array();
    
    int lis = 1;

    for(int i = 0; i < n; i++) {
        int currMAx = query(1, n, 1, 1, arr[i] - 1);
        update(1, n, 1, arr[i], currMAx + 1);
        lis = max(lis, currMAx + 1);
    }

    cout << lis;
    
    
    return 0;
}