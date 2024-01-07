#include<bits/stdc++.h>
using namespace std;

const int MOD = 997;

int expo(int base, int power) {
    if(power == 0) return 1;

    if(power % 2 == 0) {
        int x = expo(base, power / 2);
        return ((x % MOD) * (x % MOD)) % MOD;
    } else {
        int x = expo(base, power / 2);
        return ((x % MOD) * (x % MOD) * base) % MOD;
    }
}


int main() {
    cout << expo(105, 1242424);
    
    
    
    return 0;
}