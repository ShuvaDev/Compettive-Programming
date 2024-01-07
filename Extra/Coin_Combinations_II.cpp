#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;
const int MOD = 1e9 + 7;
int dp[1000000 + 5];

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for(auto &i : coins) cin >> i;
    
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= x; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
            if(dp[j] >= MOD) dp[j] %= MOD;
        }
    }

    cout << dp[x];
    
    return 0;
}