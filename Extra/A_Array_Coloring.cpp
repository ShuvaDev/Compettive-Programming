#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, total_even = 0, total_odd = 0;
        cin >> n;

        vector<int> vec(n);
        for(int i = 0; i < n; i++) {
            cin >> vec[i];
            if(vec[i] % 2) total_odd++;
            else total_even++;
        }

        if(total_odd % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    
    
    
    return 0;
}