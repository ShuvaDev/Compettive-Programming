#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX = 1e6 + 5;

// Calculate Euler Phi of N
int EulerPhi(int n) {
    int result = n;
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

// Calculate Euler Phi of 1 to N number
vector<int> ephi;
vector<bool> primes;

void rangeEulerPhi(int n) {
    ephi.resize(n + 1);
    primes.resize(n + 1);

    primes[1] = 0;
    for(int i = 1; i <= n; i++) ephi[i] = i;
    for(int i = 1; i <= n; i++) primes[i] = 1;

    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            ephi[i] -= ephi[i] / i;
            for(int j = i + i; j <= n; j += i) {
                primes[j] = 0;
                ephi[j] -= ephi[j] / i;
            }
        }
    }
}

int main() {
    
    
    rangeEulerPhi(300);

    for(int i = 1; i < 300; i++) {
        if(EulerPhi(i) != ephi[i]) {
            cout << i << endl;
        }
    }
    cout << "OK";
    return 0;
}