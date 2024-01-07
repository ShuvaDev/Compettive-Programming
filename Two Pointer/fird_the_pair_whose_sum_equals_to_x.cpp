// Find the pair whose sum equal to X;
#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int main() {
    
    int ara[] = {10, 20, 30, 40, 50};
    int X = 90;

    int L = 0, R = 4, flag = 0, ind1, ind2;

    while(L < R) {
        if(ara[L] + ara[R] == X) {
            ind1 = L, ind2 = R;
            flag = 1;
            break;
        } else if(ara[L] + ara[R] > X) {
            R = R - 1;
        } else {
            L = L + 1;
        }
    }
    if(flag) cout << ara[ind1] << " " << ara[ind2];
    else cout << "It's not possible\n";
    
    return 0;
}