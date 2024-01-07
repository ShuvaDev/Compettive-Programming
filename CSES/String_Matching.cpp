#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

vector<long long> pHash, expo;

const int MOD = 1e9 + 7;
const int BASE = 257;

void genereatePrefixHash(string &str) {
    pHash.resize(str.size());
    expo.resize(str.size());

    pHash[0] = str[0];
    expo[0] = 1;

    for(int i = 1; i < str.size(); i++) {
        pHash[i] = (pHash[i - 1] * BASE) + str[i];
        if(pHash[i] > MOD) pHash[i] %= MOD;

        expo[i] = (expo[i-1] * BASE) % MOD;
    }
}

long long hashValue(string &str) {
    long long hValue = str[0];

    for(int i = 1; i < str.size(); i++) {
        hValue = (hValue * BASE) + str[i];
        if(hValue > MOD) hValue %= MOD;
    }
    return hValue;
}

int getRangeHash(int l, int r) {
    if(l == 0) return pHash[r];

    auto h1 = pHash[r];
    auto h2 = pHash[l - 1] * expo[r - l + 1];

    if(h2 > MOD) h2 %= MOD;

    return (h1 - h2 + MOD) % MOD;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    genereatePrefixHash(s1);
    long long hValue2 = hashValue(s2), count = 0;

    for(int i = 0; i + s2.size() <= s1.size(); i++) {
        int hValue1 = getRangeHash(i, i + s2.size() - 1);

        if(hValue1 == hValue2) {
            count++;
        }
    }

    cout << count;
    
    
    
    return 0;
}