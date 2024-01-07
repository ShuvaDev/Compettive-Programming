#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int dp[1000005];

/*
int findCombination(int n) {
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];

    dp[n] = 0;

    for(int face = 1; face <= 6; face++) {
        if(face <= n) {
            dp[n] = dp[n] + findCombination(n - face);
            if(dp[n] >= MOD) dp[n] %= MOD;
        }
    }
    return dp[n];
}
*/

int findCombination(int S) {
    dp[0] = 1;

    for(int s = 1; s <= S; s++) {
        for(int face = 1; face <= 6; face++) {
            if(s < face) break;

            dp[s] += dp[s - face];
            if(dp[s] >= MOD) dp[s] %= MOD;
        }
    }
    return dp[S];

}

int main() {
    int n; 
    cin >> n;

    // memset(dp, -1, sizeof dp);
    memset(dp, 0, sizeof dp);

    cout << findCombination(n);
    
    
    
    return 0;
}