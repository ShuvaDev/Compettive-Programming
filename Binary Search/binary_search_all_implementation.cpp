#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &vc, int x, int R) {
    int L = 0;

    while(L < R) {
        int M = L + (R - L) / 2;

        if(vc[M] >= x) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    return L;
}

int lower_bound(vector<int> &vc, int x) {
    return lower_bound(vc, x, vc.size());
}

int upper_bound(vector<int> &vc, int x) {
    return lower_bound(vc, x + 1, vc.size());
}

int first_occurence(vector<int> &vc, int x) {
    return lower_bound(vc, x, vc.size() - 1);
}

int last_occurence(vector<int> &vc, int x) {
    int L = 0, R = vc.size() - 1;

    while(L < R) {
        int M = L + (R - L + 1) / 2;

        if(vc[M] <= x) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    return R;
}


int main() {
    vector<int> vc = {10, 20, 20, 25, 30, 50, 50, 60};
    
    cout << first_occurence(vc, 50);
    
    return 0;
}