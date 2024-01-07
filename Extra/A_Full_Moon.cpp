#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    long long n, m, p;
    cin >> n >> m >> p;

    long long count = 0;
    while(m <= n) {
        count++;

        m = m + p;
    }

    cout << count;
    
    
    
    return 0;
}