#include<bits/stdc++.h>
using namespace std;

const int BASE = 257;
const int MOD = 1e9 + 7;

vector<long long> pHash, revpHash;
vector<long long> expo;

void generaterevPrefixHash(string &str) {
    revpHash.clear();
    revpHash.resize(str.size());

    revpHash[0] = str[0];

    for(int i = 1; i < str.size(); i++) {
        revpHash[i] = (revpHash[i-1] * BASE) + str[i];
        if(revpHash[i] > MOD) revpHash[i] %= MOD;
    }
}

void generatePrefixHash(string &str) {
    pHash.clear();
    expo.clear();
    pHash.resize(str.size());
    expo.resize(str.size());

    pHash[0] = str[0];
    expo[0] = 1;

    for(int i = 1; i < str.size(); i++) {
        pHash[i] = (pHash[i-1] * BASE) + str[i];
        if(pHash[i] > MOD) pHash[i] %= MOD;
        expo[i] = (expo[i - 1] * BASE) % MOD;
    }
}

long long getHash(int l, int r) {
    if(l == 0) return pHash[r];

    auto h1 = pHash[r];
    auto h2 = pHash[l - 1] * expo[r-l+1];

    if(h2 > MOD) h2 %= MOD;

    return (h1 - h2 + MOD) % MOD;
}

int main() {
    int t, cs = 1;
    string str, rev_str;
    cin >> t;

    while(t--) {
        cin >> str;
        rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        generatePrefixHash(str);
        generaterevPrefixHash(rev_str);

        for(int i = 0; i < str.size(); i++) {
            auto h1 = getHash(i, str.size() - 1);
            auto h2 = revpHash[rev_str.size() - 1 - i];

            if(h1 == h2) {
                cout << "Case " << cs++ << ": ";
                if(i == 0) cout << str.size() << endl;
                else {
                    int count = 0;
                    count += i;
                    cout << count + str.size() << endl;
                }
                break;
            }
        }
    }

    
    return 0;
}