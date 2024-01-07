#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    long long n, dw = 5, count = 0;
    cin >> n;
    
    while(n / dw) {
        count += n / dw;
        dw = dw * 5;
    }

    cout << count;
    
    return 0;
}