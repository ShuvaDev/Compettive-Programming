// 0-1 Knapsack
#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<int> price(1005), page(1005);


/**
// Recursive DP
int dp[1005][100005];
int findMaxPage(int pos, int remPrice) {
    if(pos >= n) return 0;
    if(dp[pos][remPrice]) return dp[pos][remPrice];

    int taken = 0, not_taken = 0;
    if(remPrice >= price[pos]) {    
        taken = page[pos] + findMaxPage(pos + 1, remPrice - price[pos]);
    }
    not_taken = findMaxPage(pos + 1, remPrice);

    return dp[pos][remPrice] = max(taken, not_taken);
}
**/

// Iterative DP
int dp[100005];

int findMaxPage() {
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        dp[i] = INT_MIN / 2;
    }

    for(int i = 0; i < n; i++) {
        for(int p = x; p >= price[i]; p--) {
            if(dp[p] < page[i] + dp[p - price[i]]) {
                dp[p] = page[i] + dp[p - price[i]];
            }
        }
    }
    return *max_element(begin(dp), end(dp));

}


int main() {
    cin >> n >> x;
    
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> page[i];
    }
    // cout << findMaxPage(0, x);

    
    cout << findMaxPage();

    return 0;
}