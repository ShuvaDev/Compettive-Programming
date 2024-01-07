#include<bits/stdc++.h>
using namespace std;
/*
    Fermat Little Theorem: 
        a^p % p = a
        a^p-1 % p = 1
        a^p-2 % p = a^-1
*/

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

int inverse_mod(int a, int b) {
    return (a * expo(b, MOD - 2)) % MOD;
}

int main() {
    // a / b % MOD = ?

    cout << inverse_mod(5, 8);
    

    return 0;
}