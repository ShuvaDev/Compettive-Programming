#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int n, d, p;
    cin >> n >> d >> p;
    long long sum = 0;
    vector<int> vc(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &vc[i]);
    }

    sort(vc.begin(), vc.end());

    int i = n - 1;
    while(i >= 0) {
        long long r1 = 0;
        for(int j = 1; j <= d && i >= 0; j++) {
            r1 += vc[i];
            i--;
        }

        if(p <= r1) {
            sum += p;
        } else {
            sum += r1;
        }
    }

    cout << sum;
    
    
    return 0;
}