#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n, sz;
        cin >> n;
        
        sz = (n * (n - 1)) / 2;

        vector<int> vec(sz);
        map<int, int> mp;

        for(int i = 0; i < sz; i++) {
            scanf("%d", &vec[i]);
            mp[vec[i]]++;
        }   

        int i = 1, last_elem, total_printed = 0;
        for(auto &[k, v] : mp) {
            while(mp[k]) {
                cout << k << " ";
                mp[k] -= (n - i);
                i++;
                last_elem = k;
                total_printed++;
            }
        }
        for(int i = 1; i <= n - total_printed; i++) {
            cout << last_elem;
        }
        cout << endl;
        /*
        
            
        
        */
    }

    
    
    
    
    return 0;
}