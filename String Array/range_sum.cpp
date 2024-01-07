#include<bits/stdc++.h>
using namespace std;

int arr[10000], csum[100000];
int main() {

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];

    // Calculate prefix / cumulative sum
    csum[0] = arr[0];

    for(int i = 1; i < n; i++) {
        csum[i] = csum[i-1] + arr[i];
    }
    
    // Range sum
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        if(l == 0) cout << csum[r] << endl;
        else cout << csum[r] - csum[l-1] << endl;
    }
    
    
    return 0;
}