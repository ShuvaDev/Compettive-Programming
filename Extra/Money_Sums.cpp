#include<bits/stdc++.h>
using namespace std;

vector<int> coin;
int dp[100000 + 5];

int main() {
    int n;
    cin >> n;

    int sum = 0;  
    coin.resize(n);

    for(auto &i : coin) {
        cin >> i;
        sum += i;
    }   

    dp[0] = 1;

    for(int c = 0; c < n; c++) {
        for(int s = sum; s >= coin[c]; s--) {
            if(dp[s - coin[c]] != 0) {
                dp[s] = 1;
            }
        }
    }

    int count;
    count = accumulate(dp, dp + sum, 0);

    cout << count << endl;

    for(int i = 1; i <= sum; i++) {
        if(dp[i]) {
            cout << i << " ";
        }
    }



    
    
    return 0;
}