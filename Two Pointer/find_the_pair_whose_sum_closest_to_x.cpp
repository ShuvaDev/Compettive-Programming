// Find the pair whose sum closest to X;
#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int main() {
    
    int ara[] = {10, 20, 30, 40, 50};
    int X = 92;

    int L = 0, R = 4, diff = INT_MAX, ind1, ind2;

    while(L < R) {
        int sum = ara[L] + ara[R];
        if(abs(sum-X) < diff) {
            diff = abs(sum - X);
            ind1 = L, ind2 = R;
        }
        if(sum > X) R = R - 1;
        else L = L + 1;
    }
    cout << ara[ind1] << " " << ara[ind2];
    
    return 0;
}