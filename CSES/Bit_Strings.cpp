#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    long long result = 1;

    for(int i = 1; i <= n; i++) {
        result *= 2;
        if(result > MOD) result %= MOD;
    }
    
    cout << result;
    
    
    return 0;
}