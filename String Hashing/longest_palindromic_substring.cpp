#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;


const int BASE = 257;
const int MOD = 1e9 + 7;
const int MAX_SIZE = 1e5;

vector<long long> expo(MAX_SIZE);

vector<long long> generatePrefixHash(string &str) {
    vector<long long> pHash(str.size());

    pHash[0] = str[0];

    for(int i = 1; i < str.size(); i++) {
        pHash[i] = (pHash[i - 1] * BASE) + str[i];
        if(pHash[i] > MOD) pHash[i] %= MOD;
    }

    return pHash;
}

void generateExpo() {
    expo[0] = 1;
    for(int i = 1; i <= MAX_SIZE; i++) {
        expo[i] = expo[i - 1] * BASE;
        if(expo[i] > MOD) expo[i] %= MOD;
    }
}

int getRangeHash(int l, int r, vector<long long> &pHash) {
    if(l == 0) return pHash[r];

    auto h1 = pHash[r];
    auto h2 = pHash[l - 1] * expo[r - l + 1];

    if(h2 > MOD) h2 %= MOD;

    return (h1 - h2 + MOD) % MOD;
}

bool isExistPalindromeOfLength(int len, vector<long long> &pHash, vector<long long> &revPHash) {
    int l1, l2, r1, r2;

    for(int i = 0; i + len <= pHash.size(); i++) {
        l1 = i, r1 = l1 + len - 1;
        l2 = (pHash.size() - 1) - r1, r2 = l2 + len - 1;

        auto h1 = getRangeHash(l1, r1, pHash);
        auto h2 = getRangeHash(l2, r2, revPHash);

        if(h1 == h2) return 1;
    }
    return 0;
}

vector<int> evenLen, oddLen;

void generateLen(int n) {
    for(int i = 1; i <= n; i++) {
        if(i % 2) oddLen.push_back(i);
        else evenLen.push_back(i);
    }
}
/*
    If there exist 10 length palindromic substring then there must be
    exist 8, 6, 4, 2 length palindromic substring.

    Similarly, if there exist 9 length lenth palindromic substring then
    there exist 7, 5, 3, 1 length palindromic substring.
*/

int binarySearch(int size, bool MODE, vector<long long> &pHash, vector<long long> &revPHash) {
    // if MODE = 0 then binary_search func. will work for even length palindromic substirng
    // if MODE = 1 then binary_search func. will work for odd length string
    int L = 0, R;
    if(MODE == 0) {
        R = evenLen.size() - 1;
    } else {
        R = oddLen.size() - 1;
    }

    while(L < R) {
        int M = L + (R - L + 1) / 2;

        if(MODE == 0) {
            if(isExistPalindromeOfLength(evenLen[M], pHash, revPHash)) {
                L = M;
            } else {
                R = M - 1;
            }
        } else {
            if(isExistPalindromeOfLength(oddLen[M], pHash, revPHash)) {
                L = M;
            } else {
                R = M - 1;
            }
        }
    }
    if(MODE == 0) return evenLen[R];
    else return oddLen[R];
}

int main() {
    int n;
    string str;
    cin >> n >> str;

    generateExpo();
    generateLen(n);
    auto pHash = generatePrefixHash(str);

    reverse(str.begin(), str.end());
    auto revPHash = generatePrefixHash(str);

    if(n == 1) cout << 1;
    else {
        int ans1 = binarySearch(n, 0, pHash, revPHash);
        int ans2 = binarySearch(n, 1, pHash, revPHash);
        if(max(ans1, ans2) == 2) {
            if(isExistPalindromeOfLength(2, pHash, revPHash)) {
                cout << 2;
            } else {
                cout << 1;
            }
        } else {
            cout << max(ans1, ans2);
        }
    }

    return 0;
}