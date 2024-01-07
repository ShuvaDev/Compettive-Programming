#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> vec(n);

        for(int i = 0; i < n; i++) cin >> vec[i];

        sort(vec.begin(), vec.end());

        int consec_elem = 1, MAX = 1;
        for(int i = 1; i < n; i++) {
            if(vec[i] - vec[i - 1] > k) {
                MAX = max(MAX, consec_elem);
                // cout << i << " " << consec_elem << endl;
                consec_elem = 1;
            } else {
                consec_elem++;
            }
        }
        MAX = max(MAX, consec_elem);
        cout << n - MAX << endl;
        // cout << endl << endl;
    }
    
    
    
    return 0;
}