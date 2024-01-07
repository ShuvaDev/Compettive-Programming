#include<bits/stdc++.h>
using namespace std;

// Prime factorization of a number
void prime_factorization(int n) {
    int count = 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                cout << i << " ";
                n = n / i;
            }
        }
    }
    if(n > 1) cout << n << endl;
}

// Generate Prime factor of 1 to n numbers by using idea of sieve
vector<bool> primes;
vector<vector<int>> pFactor;
void generate_primeFactor(int n) {
    primes.resize(n + 1);
    pFactor.resize(n + 1);

    for(int i = 2; i <= n; i++) {
        if(primes[i] == 0) {
            for(int j = i + i; j <= n; j += i) {
                primes[j] = 1;
                pFactor[j].push_back(i);
            }
        }
    }
}

int main() {
    // prime_factorization(223092870);

    generate_primeFactor(3000);

    for(auto i : pFactor[2310]) {
        cout << i << " ";
    }
    
    return 0;
}