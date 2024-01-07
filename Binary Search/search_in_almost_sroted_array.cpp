#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int binary_search(vector<int> &arr, int x) {
    int L  = 0, R = arr.size() - 1;

    while(L <= R) {
        int M = L + (R - L) / 2;

        if(arr[M] == x) return M;
        else if(M + 1 < arr.size() && arr[M+1] == x) return M + 1;
        else if(M - 1 > -1 && arr[M-1] == x) return M - 1;
        else {
            if(arr[M] < x) {
                L = M + 1;
            } else {
                R = M - 1;
            }
        } 
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70}; 
    int x = 90;

    cout << binary_search(arr, x);
    
    
    
    return 0;
}