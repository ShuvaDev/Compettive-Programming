// https://www.geeksforgeeks.org/floor-in-a-sorted-array/

#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int getLowerBound(vector<int> &vec, int x) {
    int L = 0, R = vec.size();

    while(L < R) {
        int M = L + (R - L) / 2;

        if(vec[M] < x) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    return L;
}

int find_floor(vector<int> &vec, int x) {
    int LB = getLowerBound(vec, x);
    if(vec[LB] != x) {
        if(LB == 0) return -1;
        else return LB-1;
    } else {
        return LB;
    }
}

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    
    cout << find_floor(vec, 9);


    
    
    return 0;
}