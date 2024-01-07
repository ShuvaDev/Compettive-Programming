#include<bits/stdc++.h>
using namespace std;

// TC: NlogN, MC: NlogN
void merge_them(vector<int> &vec, int L, int R) {
    int *temp = new int[R - L + 1];
    int M = (L + R) / 2;
    int p1 = L, p2 = M + 1, ind = 0;

    while(p1 <= M && p2 <= R) {
        if(vec[p1] <= vec[p2]) {
            temp[ind++] = vec[p1];
            p1++;
        } else {
            temp[ind++] = vec[p2];
            p2++;
        }
    }

    while(p1 <= M) {
        temp[ind++] = vec[p1];
        p1++;
    }

    while(p2 <= R) {
        temp[ind++] = vec[p2];
        p2++;
    }

    for(int i = 0; i < (R - L + 1); i++) {
        vec[L + i] = temp[i];
    }
    
}

void merge_sort(vector<int> &vec, int L, int R) {
    if(L >= R) return;
    int M = (L + R) / 2;

    merge_sort(vec, L, M);
    merge_sort(vec, M + 1, R);

    merge_them(vec, L, R);
}
 
void merge_sort(vector<int> &vec) {
    int L = 0, R = (int)vec.size() - 1;

    merge_sort(vec, L, R);
}

int main() {
    vector<int> vec = {10, -4, 4, 9, 1, 12, 8};
    
    merge_sort(vec);
    for(auto i : vec) cout << i << " ";
    return 0;
}