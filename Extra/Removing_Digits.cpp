#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int findNumberOfStep(int n) {
    if(n == 0) return 0;

    else {
        int N = n, maxDigit = 0;
        while(N) {
            maxDigit = max(maxDigit, N % 10);
            N = N / 10;
        }
        return 1 + findNumberOfStep(n - maxDigit);
    }
}

int main() {
    int n;
    cin >> n;

    cout << findNumberOfStep(n);
    
    
    
    return 0;
}