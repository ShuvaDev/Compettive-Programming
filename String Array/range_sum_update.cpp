#include<bits/stdc++.h>
using namespace std;

int point_update[10000];
int main() {
    /*
        You are given an array A and Q query
        In Q line you are given l, r, v
        You need to add v to subarray (l, r)
    */
    int n = 9;
    int A[n] = {10, 11, 2, 3, 4, 5, 18, 19};
    int Q;
    cin >> Q;
    

    while(Q--) {
        int l, r, v;
        cin >> l >> r >> v;

        point_update[l] += v;
        if(r != n-1) point_update[r+1] -= v;
    }   

    for(int i = 1; i < n; i++) {
        point_update[i] = point_update[i-1] + point_update[i];
    }

    for(int i = 0; i < n; i++) {
        cout << A[i] + point_update[i] << " ";
    }
    
    
    return 0;
}