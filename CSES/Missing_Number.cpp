#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    long long n, x, t_sum, sum = 0;
    cin >> n;


    for(int i = 0; i < n - 1; i++) {
        cin >> x;
        sum += x;
    }

    t_sum = n * (n + 1) / 2;

    cout << t_sum - sum;
    
    return 0;
}