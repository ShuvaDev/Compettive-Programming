#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int dp[1000000 + 5];

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coin(n);
    for(auto &i : coin) cin >> i;

    dp[0] = 1;

    sort(coin.begin(), coin.end());

    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            // coin[j] nile i kotovabe banano jai
            if(coin[j] > i) break;

            dp[i] = (dp[i] + dp[i - coin[j]]) % MOD;
        }
    }

    if(dp[x] == 0) cout << -1;
    else cout << dp[x];
    
    return 0;
}