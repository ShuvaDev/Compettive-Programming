#include<bits/stdc++.h>
using namespace std;

int getLowerBound(vector<int> &arr, int target) {
    int L = 0, R = arr.size();

    while(L < R) {
        int M = L + (R - L) / 2;
        if(target > arr[M]) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    return L;
}

/*
int getUpperBound1(vector<int> &arr, int target) {
    int L = 0, R = arr.size();

    while(L < R) {
        int M = L + (R - L) / 2;
        if(target >= arr[M]) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    return L;
}
*/

int getUpperBound(vector<int> &arr, int target) {
    return getLowerBound(arr, target + 1);
}

int main() {
    vector<int> arr = {10, 10, 20, 30, 30, 40, 40, 45, 50};
    int target = -5;

    cout << getUpperBound(arr, 10);
    
    
    return 0;
}