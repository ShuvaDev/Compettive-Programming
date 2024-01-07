#include<bits/stdc++.h>
using namespace std;

// TC: NlogN, MC: logN
int create_partition(int L, int R, vector<int> &vec) {
    int i = L - 1, j = L, pivot = vec[R];

    while(j < R) {
        if(vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
        j++;
    }
    swap(vec[i + 1], vec[R]);

    return i + 1;
}

void quick_sort(int L, int R, vector<int> &vec) {
    if(L >= R) return;
    int p = create_partition(L, R, vec);

    while(p > 0 && vec[p] == vec[p - 1]) p--; // For same elements
    quick_sort(L, p - 1, vec);

    while(p < R && vec[p] == vec[p + 1]) p++;
    quick_sort(p + 1, R, vec);
}

void quick_sort(vector<int> &vec) {
    quick_sort(0, vec.size() - 1, vec);
}

mt19937 rng(0);
int main() {
    int n = 10000;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        vec[i] = rng() % INT_MAX;
    }
    // shuffle(vec.begin(), vec.end(), rng);
    quick_sort(vec);

    cout << is_sorted(vec.begin(), vec.end());
    
    return 0;
}