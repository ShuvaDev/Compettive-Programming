#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int lower_bound(vector<int> &vc, int x) {
    int L = 1, R = vc.size();


    while(L < R) {
        int M = L + (R - L) / 2;
        
        if(vc[M] >= x) R = M;
        else if(vc[M] < x) L = M + 1;

    }
    return L;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vc(n + 1);
    for(int i = 1; i <= n; i++) cin >> vc[i];

    while(k--) {
        int x;
        cin >> x;

        cout << lower_bound(vc, x) << endl;
    }
    
    
    
    return 0;
}