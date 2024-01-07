// Find out kth smallest number using quick sort Leetcode problem

#include<bits/stdc++.h>
using namespace std;

int quick_partition(int L, int R, vector<int> &vec) {
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

void partial_sort(int k, vector<int> &vec) {
    int L = 0, R  = vec.size() - 1;

    while(L < R) {
        int p = quick_partition(L, R, vec);

        if(p == k) break;
        else if(p < k) L = p + 1;
        else R = p - 1;
    }
}

int main() {
    vector<int> vec = {8, -2, 7, 5, 6, 2};

    int k = 2;
    partial_sort(k - 1, vec);

    cout << vec[k - 1];
    
    
    
    return 0;
}