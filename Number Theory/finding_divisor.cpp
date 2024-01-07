#include<bits/stdc++.h>
using namespace std;

// print divisor of a number
void print_divisor(int n) {
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(i * i == n) cout << i << " ";
            else cout << i << " " << n / i << " ";
        }
    }
}

// generate divisor of 1 to n number using the idea of sieve
vector<vector<int>> divisor;
void generate_divisor(int n) {
    divisor.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
           divisor[j].push_back(i);
        }
    }
}

int main() {
    // print_divisor(12);
    generate_divisor(100);

    for(auto i : divisor[50]) {
        cout << i << " ";
    }
    
    
    return 0;
}