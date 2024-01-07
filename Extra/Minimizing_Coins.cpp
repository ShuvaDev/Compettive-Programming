#include<bits/stdc++.h>
using namespace std;

int dp[1000000 + 5];
int minCoin[1000000 + 5];

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coin(n);

    for(auto &i : coin) cin >> i;

    sort(coin.begin(), coin.end());

    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(auto &c : coin) {
            if(c > i) break;

            if(dp[i - c] != 0) {
                dp[i] = 1;
                if(minCoin[i] == 0) {
                    minCoin[i] = 1 + minCoin[i - c];
                } else {
                    minCoin[i] = min(minCoin[i], 1 + minCoin[i - c]);
                }
            }
        }
    }
    
    if(minCoin[x] == 0) cout << -1;
    else cout << minCoin[x];
    
    return 0;
}