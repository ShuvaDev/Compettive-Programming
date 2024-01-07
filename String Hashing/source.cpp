#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 257;

vector<long long> pHash, expo;

void generatePrefixHash(string &str) {
    pHash.clear();
    expo.clear();

    pHash.resize(str.size());
    expo.resize(str.size());

    expo[0] = 1;
    pHash[0] = str[0];

    for(int i = 1; i < str.size(); i++) {
        pHash[i] = (pHash[i-1] * BASE) + str[i];
        if(pHash[i] > MOD) pHash[i] %= MOD;

        expo[i] = (expo[i-1] * BASE) % MOD;
    }
}

int getRangeHash(int l, int r) {
    if(l == 0) return pHash[r];

    auto h1 = pHash[r];
    auto h2 = pHash[l - 1] * expo[r - l + 1];

    if(h2 > MOD) h2 %= MOD;

    return (h1 - h2 + MOD) % MOD;
}

int main() {
    string str = "ashuvadshuvac";
    generatePrefixHash(str);

    cout << getRangeHash(1, 5) << endl;
    cout << getRangeHash(7, 11) << endl;

    return 0;
}