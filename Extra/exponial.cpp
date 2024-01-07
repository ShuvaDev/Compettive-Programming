#include<bits/stdc++.h>
using namespace std;

long long bigMod(int a, int b, int M) {
    if(b == 0) return 1;
    if(b == 1) return a;
    
    if(b % 2 == 0) {
        auto x = bigMod(a, b / 2, M) % M;
        return (x * x) % M;
    } else {
        auto x = bigMod(a, b / 2, M) % M;
        return (a * x * x) % M;
    }
}

long long eulerPhi(int n) {
    long long result = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            result -=  result / i;
            while(n % i == 0) {
                n = n / i;
            }
        }
    } 
    if(n > 1) result -=  result / n;
    return result;
}

long long findExponial(int n, int m) {
    if(m == 1) return 0;
    if(n == 2) return 2 % m;
    if(n == 3) return 9 % m;
    if(n == 4) return bigMod(4, 9, m);

    long long EP = eulerPhi(m);
    return bigMod(n, findExponial(n - 1, EP) + EP, m);
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << findExponial(n, m);
    
    return 0;
}